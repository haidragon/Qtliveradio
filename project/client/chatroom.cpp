#include "chatroom.h"
#include "ui_chatroom.h"
#include<QDateTime>
#include<QMessageBox>
#include"roommanager.h"
#include"videosurface.h"
#include<QPoint>
#include<QMovie>

/*
函数功能：构造函数
参数：ClientSocket *cs, QTcpSocket *socket, QString curRoom,user_t user, QWidget *parent
返回值：无
*/
ChatRoom::ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                   user_t user, QWidget *parent) :
    QDialog(parent),cs(cs),socket(socket),curRoom(curRoom),user(user),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this); //安装监听

    uiDesign(); //界面布局
    showChatList();//聊天用户列表

    QObject::connect (cs, SIGNAL(sigChatName(user_t)),
                      this, SLOT(onsigChatName(user_t)));
    QObject::connect (cs, SIGNAL(sigChatList(user_t)),
                      this, SLOT(onsigChatList(user_t)));
    QObject::connect (cs, SIGNAL(sigChatText(user_t)),
                      this, SLOT(onsigChatText(user_t)));
    QObject::connect(cs, SIGNAL(sigMasterExit(user_t)),
                     this, SLOT(onsigMasterExit(user_t)));
    QObject::connect (cs, SIGNAL(sigVideo(user_t)),
                      this, SLOT(onsigVideo(user_t)));
    QObject::connect (cs, SIGNAL(sigunVideo(user_t)),
                      this, SLOT(onsigunVideo(user_t)));
    QObject::connect (cs, SIGNAL(sigBs(user_t)),
                      this, SLOT(onsigBs(user_t)));

    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));

    udpVideo();
    udpAudio();
}

/*
函数功能：析构函数
参数：无
返回值：无
*/
ChatRoom::~ChatRoom()
{
    delete ui;
}


/*
函数功能：按enter发送信息
参数：QObject *obj, QEvent *ev
返回值：bool
*/
bool ChatRoom::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->textEdit){
            //是否是键盘事件
            if(ev->type() == QEvent::KeyPress){
                //将QEvent*类型转化为QKeyEvent*
                QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(ev);
                //判定是否是大键盘上的enter
                if(keyEvent->key() == Qt::Key_Return){
                    ChatRoom::on_send_clicked();    //执行发送按钮事件
                }else{
                    //继续转发
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return ChatRoom::eventFilter(obj, ev);
        }
}


/*
函数功能：界面布局
参数：无
返回值：无
*/
void ChatRoom::uiDesign()
{
    //设置窗口背景图片
    this->setStyleSheet ("background-image:url(:/image/image/pic3.png)");
    ui->listWidget->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");
    ui->textBrowser->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");
    ui->textEdit->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");

   //设置按钮图片和无边框
    ui->send->setStyleSheet("QPushButton{background-color:blue;"
                            "color: black;"
                            "border-radius: 10px;"
                            "border: 2px groove gray;"
                            "border-style: outset;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);"
                            "border-style: inset; }"
                             );
    QPixmap video(":/image/image/icon/video.png");
    QPixmap audio(":/image/image/icon/audio.png");
    QPixmap flash(":/image/image/icon/flash.jpg");
    QPixmap bs(":/image/image/icon/send.png");
    QPixmap gift(":/image/image/icon/gift.png");
    ui->send->setFlat (true);
    ui->video->setIcon (video);
    ui->video->setIconSize (QSize(35,35));
    ui->video->setFlat (true);
    ui->audio->setIcon (audio);
    ui->audio->setIconSize (QSize(35,35));
    ui->audio->setFlat (true);
    ui->chatlist_btn->setIcon (flash);
    ui->chatlist_btn->setIconSize (QSize(20,20));
    ui->chatlist_btn->setFlat (true);
    ui->bs->setIcon (bs);
    ui->bs->setIconSize (QSize(35,35));
    ui->bs->setFlat (true);
    ui->gift->setIcon (gift);
    ui->gift->setIconSize (QSize(35,35));
    ui->gift->setFlat (true);

    //显示当前用户
    QString label = "当前用户：";
    label += QString::fromLocal8Bit (user.username);
    ui->cur_user->setStyleSheet ("color:red;");
    ui->cur_user->setText (label);

    ui->textscroll->setStyleSheet ("background-image:url()");   //取消从父控件继承过来的图片背景
    ui->textscroll->setWindowOpacity (0);   //设置弹幕label透明（不遮挡后面的视频图像）
    ui->textscroll->hide();     //默认隐藏弹幕
    ui->videosurface->hide ();  //隐藏需要播放视频的label
    QPixmap pixmap(":/image/image/vpic.png");
    pixmap = pixmap.scaled(ui->videosurface->size());
    ui->videosurface->setPixmap(pixmap);

    ui->audioinput->setWindowOpacity(0);    //设置语音label透明
    ui->audioinput->hide(); //默认隐藏
    ui->audioinput->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");
    QMovie *movie = new QMovie(":/image/image/audio.gif");
    movie->setScaledSize(QSize(231,231));
    ui->audioinput->setMovie(movie);
    movie->start();
}

/*
函数功能：udp视频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpVideo()
{
    //开启摄像头
    QCameraInfo info = QCameraInfo::defaultCamera ();
    camera = new QCamera(info, this);
    VideoSurface *vf = new VideoSurface(this);
    camera->setViewfinder (vf);
    QObject::connect (vf, SIGNAL(videoChanged(QVideoFrame)),
             this, SLOT(onvideoChanged(QVideoFrame)));

    //建立udp网络连接
    socketWrite = new QUdpSocket(this);
    socketRead = new QUdpSocket(this);
    groupAddress.setAddress ("224.0.1.200");
    // groupAddress.setAddress ("239.88.88.88");   //组播地址
    socketWrite->setSocketOption (QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRead->bind (QHostAddress::AnyIPv4, 8888, QUdpSocket::ReuseAddressHint|QUdpSocket::ShareAddress);//绑定广播地址端口
    socketRead->joinMulticastGroup (groupAddress);  //添加到组播，绑定到读套接字上

    //udp读写
    QObject::connect (socketRead, SIGNAL(readyRead()),
             this, SLOT(UdpReadRead()));
}


/*
函数功能：udp音频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpAudio()
{
    socketWdaudio = new QUdpSocket(this);
    socketRdaudio = new QUdpSocket(this);
    groupAddress1.setAddress ("224.0.1.205");
    socketWdaudio->setSocketOption (QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRdaudio->bind (QHostAddress::AnyIPv4, 6666, QUdpSocket::ReuseAddressHint|QUdpSocket::ShareAddress);//绑定广播地址端口
    socketRdaudio->joinMulticastGroup (groupAddress1);  //添加到组播，绑定到读套接字上

    QObject::connect(socketRdaudio, SIGNAL(readyRead()),
                     this, SLOT(ReadyReadAudio()));
}


/*
函数功能：刚进入聊天室时告诉服务器
参数：无
返回值：无
*/
void ChatRoom::showChatList()
{
    user.type = CHATNAME;
    socket->write ((char*)&user, sizeof(user_t));
}


/*
函数功能：刚进入聊天室时加入用户列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatName (user_t user)
{
    QString chatName = QString::fromLocal8Bit (user.username);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room2.jpg"), chatName, ui->listWidget);
    ui->listWidget->setIconSize(QSize(36,36));
    ui->listWidget->addItem (item);
    QString sysInfo = "\n[系统消息：]";
    sysInfo += chatName;
    sysInfo += "已加入聊天室\n";
    ui->textBrowser->setTextColor (QColor::fromRgb (255,0,0));
    ui->textBrowser->append (sysInfo);
    ui->textBrowser->setTextColor (QColor::fromRgb (0,0,0));
}


/*
函数功能：刷新按钮
参数：无
返回值：无
*/
void ChatRoom::on_chatlist_btn_clicked()
{
    ui->listWidget->clear ();
    user.type = CHATLIST;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：显示聊天列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatList (user_t user)
{
    QString chatName = QString::fromLocal8Bit (user.chatname);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room2.jpg"), chatName, ui->listWidget);
    ui->listWidget->setIconSize(QSize(36,36));
    ui->listWidget->addItem (item);
}

/*
函数功能：发送消息按钮
参数：无
返回值：无
*/
void ChatRoom::on_send_clicked()    //文字聊天
{
    QString text = ui->textEdit->toPlainText ();
    if(text.isEmpty ()){
        QMessageBox::warning (this, "提示","内容不可为空");
        return;
    }
    QByteArray ba_text = text.toLocal8Bit ();
    char* c_text = ba_text.data ();
    strncpy(user.data, c_text, sizeof(user.data));
    if(ui->textscroll->isHidden()){ //如果弹幕屏是隐藏的为真，说明发过去的是文本信息
        user.type = TEXT;
    }
    else{   //否则发过去的就是弹幕
        user.type = BS;
    }
    ui->textEdit->clear ();
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：返回文字消息处理
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatText(user_t user)
{
    QString room = QString::fromLocal8Bit (user.roomName);

    QDateTime dt = QDateTime::currentDateTime ();
    QString str_head = QString::fromLocal8Bit (user.username);
    str_head += " ";
    str_head += dt.toString ("yyyy/MM/dd hh:mm:ss");
    QString str_body = "  ";
    str_body += QString::fromLocal8Bit (user.data);
    static int flag = -1;
    if(flag == -1){
        ui->textBrowser->setTextColor (QColor::fromRgb (50,205,50));
        flag *= -1;
    }
    else if(flag == 1){
        ui->textBrowser->setTextColor (QColor::fromRgb (0,0,255));
        flag *= -1;
    }
    ui->textBrowser->append (str_head);
    ui->textBrowser->setTextColor (QColor::fromRgb (0,0,0));
    ui->textBrowser->append (str_body);
}


/*
函数功能：关闭聊天室
参数：QCloseEvent *
返回值：无
*/
void ChatRoom::closeEvent (QCloseEvent *)
{
    RoomManager *rm = RoomManager::getInstance ();
    QString room = QString::fromLocal8Bit (user.roomName);
    rm->eraseRoom (room);

    user.type = QUIT;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：房主退出客户端通知其他人退出房间
参数：user_t user
返回值：无
*/
void ChatRoom::onsigMasterExit(user_t user)
{
    QMessageBox::warning(this, "警告", "房主已经下线，房间将暂时关闭，谢谢配合");
    this->close();
}

/*
函数功能：直播按钮
参数：无
返回值：无
*/
void ChatRoom::on_video_clicked()
{
    if(user.flag != MASTER){
        QMessageBox::warning (this, "警告", "只有房主可以开启直播");
        return;
    }
    static int fv = -1;
    if(fv == -1){
        user.type = VIDEO;      //开启视频
        QPixmap video(":/image/image/icon/video1.png");
        ui->video->setIcon (video);
        ui->video->setIconSize (QSize(35,35));
        socket->write((char*)&user, sizeof(user));
        fv *= -1;
    }
    else if(fv == 1){        //关闭视频
        user.type = UNVIDEO;
        QPixmap video(":/image/image/icon/video.png");
        ui->video->setIcon (video);
        ui->video->setIconSize (QSize(35,35));
        socket->write((char*)&user, sizeof(user));
        fv *= -1;
    }
}


/*
函数功能：开启直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigVideo (user_t user)
{
    if(user.flag != MASTER){
        QMessageBox::information (this, "提示", "房主正在发起直播！");
    }
    ui->videosurface->show ();
    camera->start ();
    QPixmap video(":/image/image/icon/video1.png");
    ui->video->setIcon (video);
    ui->video->setIconSize (QSize(35,35));
}


/*
函数功能：关闭直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigunVideo (user_t user)
{
    if(user.flag != MASTER){
        QMessageBox::information (this, "提示", "房主已经关闭直播！");
    }
    camera->stop ();
    ui->videosurface->hide ();

    QPixmap video(":/image/image/icon/video.png");
    ui->video->setIcon (video);
    ui->video->setIconSize (QSize(35,35));
}


/*
函数功能：udp接收图片
参数：无
返回值：无
*/
void ChatRoom::UdpReadRead ()
{
    static QByteArray byteArray(500000,0);   //字符数组；
        //数据流
    static QDataStream dataStream(&byteArray,QIODevice::ReadWrite);
    static int readed = 0;
    while(socketRead->hasPendingDatagrams()){
        char buffer[1024] = {0};
        readed += socketRead->readDatagram(buffer,1024);
        dataStream.writeRawData(buffer,1024);
    }

    if(readed>=102400){
        QImage image = QImage((uchar*)byteArray.data(),
                       160,
                       96,
                       640,
                       QImage::Format_RGB32);
        QPixmap map =QPixmap::fromImage(image);
        map = map.scaled (ui->videosurface->size ());
        ui->videosurface->setPixmap(map);
        readed = 0;
        dataStream.device ()->seek (0);
    }
}


/*
函数功能：获取视频采集的图片并通过udp发送出去
参数：QVideoFrame curFrame
返回值：无
*/
void ChatRoom::onvideoChanged(QVideoFrame curFrame)
{
    static int i = 0;
    i++;
    QVideoFrame frame(curFrame);
    frame.map(QAbstractVideoBuffer::ReadOnly);
    //通过QVideoFrame对象构建QImage对象
    QImage image(frame.bits(),
                  frame.width(),
                 frame.height(),
                 QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));

    //将图像旋转180
    QMatrix matrix;
    matrix.rotate(180);
    image = image.transformed(matrix);
    image = image.scaled (160, 96);

    if(i % 2 == 0){
        int byteCount = image.byteCount();
        int readed = 0;
        uchar* data = image.bits();
        while(readed < byteCount){
            int count = socketWrite->writeDatagram((char*)data + readed,
                    1024, QHostAddress::Broadcast,8888);
            readed += count;
        }
    }
}


/*
函数功能：弹幕按钮
参数：无
返回值：无
*/
void ChatRoom::on_bs_clicked()
{
    static int bs = -1;
    if(bs == -1){
        ui->textscroll->show ();
        QPixmap send(":/image/image/icon/send1.png");
        ui->bs->setIcon (send);
        ui->bs->setIconSize (QSize(35,35));
        bs *= -1;
    }
    else if(bs == 1){
        ui->textscroll->hide ();
        QPixmap send(":/image/image/icon/send.png");
        ui->bs->setIcon (send);
        ui->bs->setIconSize (QSize(35,35));
        bs *= -1;
    }
}

/*
函数功能：弹幕处理
参数：user_t user
返回值：无
*/
void ChatRoom::onsigBs (user_t user)
{
    QString bs_text = QString::fromLocal8Bit(user.data);

    label = new QLabel(bs_text, ui->textscroll);
    label->setStyleSheet("color:red");
    label->setFont(QFont("Timers", 28 , QFont::Bold));
    int len = qrand()% ui->textBrowser->height() + 0;//纵坐标为随机值
    label->move(0, len);
    label->adjustSize(); //设置label大小自适应字体长度
    timer->start(10);
}


/*
函数功能：定时器事件
参数：无
返回值：无
*/
void ChatRoom::onTimeOut()
{
    const QPoint& p = label->pos();
    if(p.x() < (ui->textBrowser->width())){
        label->move(p.x() + 1, p.y());
        label->show();
        label->update();
    }
    else{
        label->hide();
    }
}


/*
函数功能：音频按钮
参数：无
返回值：无
*/
void ChatRoom::on_audio_clicked()
{
    static int af = -1;
    if(af == -1){
        QPixmap audio(":/image/image/icon/audio1.png");
        ui->audio->setIcon (audio);
        ui->audio->setIconSize (QSize(35,35));
        ui->audioinput->show();
        file =new QFile();
        filename = "C:\\Users\\Public\\Music\\sourse.raw"; //源音频文件路径
        audioname = "C:\\Users\\Public\\Music\\sourse.wav";    //转换后音频文件路径
        recname = "C:\\Users\\Public\\Music\\recive.wav";  //udp传输之后音频文件路径
        file->setFileName(filename);//设置其实设置音频文件的存放路径(输入音频名及存放路径)
        bool is_open =file->open(QIODevice::WriteOnly | QIODevice::Truncate);
        if(!is_open)
        {
            qDebug()<<"打开文件失败"<<endl;
            return;
        }

        // 设置音频文件格式;
        QAudioFormat format;
        // 设置采样频率;
        format.setSampleRate(8000);
        // 设置通道数;
        format.setChannelCount(1);
        // 设置每次采样得到的样本数据位值;
        format.setSampleSize(8);
        // 设置编码方法;
        format.setCodec("audio/pcm");
        // 设置采样字节存储顺序;
        format.setByteOrder(QAudioFormat::LittleEndian);
        // 设置采样类型;
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        QString str=info.deviceName();
        qDebug()<<"使用的录音设备是:"<<str<<endl;

        // 判断当前设备设置是否支持该音频格式;
        if(!info.isFormatSupported(format))
        {
            format = info.nearestFormat(format);
        }
        input = new QAudioInput(format, this);

        input->start(file); //录音

        af *= -1;
    }
    else if(af == 1){
        QPixmap audio(":/image/image/icon/audio.png");
        ui->audio->setIcon (audio);
        ui->audio->setIconSize (QSize(35,35));
        ui->audioinput->hide();

        input->stop();
        file->close();
        // 将生成的.raw文件转成.wav格式文件;
        if (addWavHeader(filename, audioname) > 0){
            sendMsg(audioname);
        }
        af *= -1;
    }
}


/*
函数功能：将生成的.raw文件转成.wav格式文件;
参数：QString catheFileName , QString wavFileName
返回值：qint64
*/
qint64 ChatRoom::addWavHeader(QString catheFileName , QString wavFileName)
{
    // 开始设置WAV的文件头
    WAVFILEHEADER WavFileHeader;
    qstrcpy(WavFileHeader.RiffName, "RIFF");
    qstrcpy(WavFileHeader.WavName, "WAVE");
    qstrcpy(WavFileHeader.FmtName, "fmt ");
    qstrcpy(WavFileHeader.DATANAME, "data");

    // 表示 FMT块 的长度
    WavFileHeader.nFmtLength = 16;
    // 表示 按照PCM 编码;
    WavFileHeader.nAudioFormat = 1;
    // 声道数目;
    WavFileHeader.nChannleNumber = 1;
    // 采样频率;
    WavFileHeader.nSampleRate = 8000;

    // nBytesPerSample 和 nBytesPerSecond这两个值通过设置的参数计算得到;
    // 数据块对齐单位(每个采样需要的字节数 = 通道数 × 每次采样得到的样本数据位数 / 8 )
    WavFileHeader.nBytesPerSample = 2;
    // 波形数据传输速率
    // (每秒平均字节数 = 采样频率 × 通道数 × 每次采样得到的样本数据位数 / 8  = 采样频率 × 每个采样需要的字节数 )
    WavFileHeader.nBytesPerSecond = 16000;

    // 每次采样得到的样本数据位数;
    WavFileHeader.nBitsPerSample = 16;

    QFile cacheFile(catheFileName);
    QFile wavFile(wavFileName);

    if (!cacheFile.open(QIODevice::ReadWrite))
    {
        return -1;
    }
    if (!wavFile.open(QIODevice::WriteOnly))
    {
        return -2;
    }

    int nSize = sizeof(WavFileHeader);
    qint64 nFileLen = cacheFile.bytesAvailable();

    WavFileHeader.nRiffLength = nFileLen - 8 + nSize;
    WavFileHeader.nDataLength = nFileLen;

    // 先将wav文件头信息写入，再将音频数据写入;
    wavFile.write((char *)&WavFileHeader, nSize);
    wavFile.write(cacheFile.readAll());
    cacheFile.close();
    wavFile.close();
    qDebug()<<"size = "<<nFileLen;
    return nFileLen;
}


/*
函数功能：通过udp发送音频文件
参数：QString audioname
返回值：无
*/
void ChatRoom::sendMsg(QString audioname)
{
    QFile sendfile(audioname);
    if (!sendfile.open(QIODevice::ReadWrite))
    {
        qDebug()<<"我发送过，但是失败了";
        return;
    }
    while(!sendfile.atEnd()){
        QByteArray line = sendfile.read(300);
        socketWdaudio->writeDatagram(line, QHostAddress::Broadcast, 6666);
    }
     sendfile.close();
}


/*
函数功能：udp接收音频文件
参数：无
返回值：无
*/
void ChatRoom::ReadyReadAudio()
{
    QFile rcvfile(recname);
    if (!rcvfile.open(QIODevice::ReadWrite))
    {
        qDebug()<<"我收到过，但是失败了";
        return;
    }

    while(socketRdaudio->hasPendingDatagrams()){
        QByteArray data(300, 0);
        socketRdaudio->readDatagram(data.data(), 300);
        rcvfile.write(data.data(),data.size());
    }
    QString str = QString::fromLocal8Bit(user.username);
    str += "发来语音消息，是否立即接收？";
    QMessageBox::StandardButton sb = QMessageBox::information(this, "提示", str,
                            QMessageBox::Yes, QMessageBox::No);
    if(sb == QMessageBox::Yes){
        dispaly();
    }
    rcvfile.close();
}


/*
函数功能：播放音频文件
参数：无
返回值：无
*/
void ChatRoom::dispaly()
{
    file->setFileName(recname);
    file->open(QIODevice::ReadOnly);

    // 设置音频文件格式;
    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    //开始播放
    output = new QAudioOutput(format);
    output->start(file);
}


/*
函数功能：送礼按钮
参数：无
返回值：无
*/
void ChatRoom::on_gift_clicked()
{
    QMessageBox::information(this, "提示","敬请期待");
}
