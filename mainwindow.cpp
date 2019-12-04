#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::resizeEvent(QResizeEvent *e) {
    if(e->size() != e->oldSize()){
        this->inputT->resize(this->width() / 1.64, this->height() / 1);
        int x = this->inputT->size().height();
        int y = this->inputT->size().width();
        //this->history->setGeometry(this->inputT->pos().y() + this->inputT->size().height() , 15, 180, 20);
        this->history->setGeometry(y * 1.2, x / 20, y / 2.5, y / 20);
        this->files->setGeometry(y * 1.01, x / 10, y / 1.6, y / 7);
        this->WordSearchLabel->setGeometry(y * 1.2, x/3.8, y / 2.5, y / 20);
        this->search->setGeometry(y * 1.01, x/3.2, y/2.1, y/10);
        this->searchBtn->setGeometry(y * 1.48, x/3.2, y/6, y/10);
        this->checkWordRegicst->setGeometry(y*1.07, x/2.5, y/2, y/12);
        this->searchAll->setGeometry(y*1.07, x/2.2,y/2,y/12);
        this->hoverOnOff->setGeometry(y*1.29, x/2.15, y/3, y/15);
        this->plus->setGeometry(y*1.046, x/1.75, y/12,y/12);
        this->minus->setGeometry(y * 1.046, x/1.56, y/11.5, y/11.5);
        this->labelPlus->setGeometry(y*1.14, x/1.71, y/2.5,y/20);
        this->labelMinus->setGeometry(y*1.14, x/1.52, y/2.5, y/20);
        this->BookWords->setGeometry(y*1.046, x/1.34, y/2.5, y/17);
        this->slider->setGeometry(y*1.046, x/1.12, y/2.5, y/20);
        this->labelSizeInterval->setGeometry(y*1.08, x/1.22, y/2, y/12);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setw(this->START_W, this->START_H);
    this->setMaximumSize(MAX_W, MAX_H);
    this->setMinimumSize(MIN_W, MIN_H);
    this->fSize = 15;
    QFont f("Helvetica");
    f.setPixelSize(fSize);
    f.setUnderline(false);
    f.setItalic(false);
    f.setBold(false);


    this->BookWords = new QPushButton("Проверить правописание", this);
    this->BookWords->setGeometry(520, 450, 180,45);
    this->BookWords->setParent(this);

    this->history = new QLabel("История файлов", this);
    //this->history->setGeometry(520, 15, 180,20);
    this->history->setParent(this);

    this->WordSearchLabel = new QLabel("Поиск слова", this);
    this->WordSearchLabel->setGeometry(520, 155, 180,20);
    this->WordSearchLabel->setParent(this);

    this->checkWordRegicst = new QCheckBox("Регистронезависимость", this);
    this->checkWordRegicst->setGeometry(520, 250, 180, 45);
    this->checkWordRegicst->setParent(this);

    this->searchAll = new QCheckBox("Искать везде", this);
    this->searchAll->setGeometry(520, 280, 180, 45);
    this->searchAll->setParent(this);

    this->search = new QTextEdit("", this);
    this->search->setGeometry(520, 190, 200, 45);
    this->search->setParent(this);

    this->searchBtn = new QPushButton("search", this);
    this->searchBtn->setGeometry(720, 190, 80, 45);

    this->files = new QListWidget(this);
    this->files->setGeometry(520, 60, 250,70);

    this->label = new QLabel("", this);
    this->label->setGeometry(0,45, 800, 45);
//    this->showD = new QPushButton("save file", this);


    this->plus = new QPushButton("+", this);
    this->plus->setGeometry(510, 340, 40, 40);
    this->plus->setParent(this);

    this->minus = new QPushButton("-", this);
    this->minus->setGeometry(510, 380, 40, 40);
    this->minus->setParent(this);

    this->labelPlus = new QLabel("Увеличить текст");
    this->labelPlus->setGeometry(550, 350, 180, 20);
    this->labelPlus->setParent(this);

    this->labelMinus = new QLabel("Уменьшить текст");
    this->labelMinus->setGeometry(550, 390, 180, 20);
    this->labelMinus->setParent(this);

    this->hoverOnOff = new QPushButton("Убрать выделение", this);
    this->hoverOnOff->hide();
    this->hoverOnOff->setGeometry(630, 287, 150, 25);
    this->hoverOnOff->setParent(this);


    this->inputT = new QTextEdit("", this);
    this->inputT->setGeometry(0, 0, 500, 573);
//    this->inputT->setAlignment(Qt::Alignment)
    this->inputT->setTabChangesFocus(true);

    //this->inputT->document()->setProperty("lineHeightMode", "Text.FixedHeight");
    //this->inputT->document()->setProperty("lineHeight", 20);
    this->inputT->setFont(f);



        QMenu *file = menuBar()->addMenu("File");
        QMenu *edit = menuBar()->addMenu("edit");
        QMenu *font = menuBar()->addMenu("fonts");
        QMenu *close = menuBar()->addMenu("close");
        QAction *chooseText = new QAction(tr("fonts"), this);
        QAction *open = new QAction(tr("open"), this);
        QAction *closeApp = new QAction(tr("close"), this);
        QAction *newFileSave = new QAction(tr("Save file"), this);
        QAction *editColor = new QAction(tr("Color"), this);
        QAction *editUnderline = new QAction(tr("Underline"), this);
        QAction *editBold = new QAction(tr("Bold"), this);
        QAction *editItalic = new QAction(tr("Italic"), this);
//        QAction *colorMainWindow = new QAction(tr("Color main window"), this);


        file->addAction(newFileSave);
        file->addAction(open);
        font->addAction(chooseText);
        edit->addAction(editColor);
        edit->addAction(editUnderline);
        edit->addAction(editBold);
        edit->addAction(editItalic);
//        edit->addAction(colorMainWindow);
        close->addAction(closeApp);

        connect(BookWords, SIGNAL(clicked()), this, SLOT(checkgramary()));
        connect(hoverOnOff, SIGNAL(clicked()), this, SLOT(hoverOnOrOff()));
        connect(checkWordRegicst, SIGNAL(clicked()), this, SLOT(checkRegisterWords()));
        connect(searchBtn, SIGNAL(clicked()), this, SLOT(searchWord()));
        connect(chooseText, SIGNAL(triggered()), this, SLOT(chooseYourFont()));
        connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
        connect(newFileSave, SIGNAL(triggered()), this, SLOT(save()));
        connect(editUnderline, SIGNAL(triggered()), this, SLOT(setUnderline()));
        connect(editBold, SIGNAL(triggered()), this, SLOT(setBold()));
        connect(editItalic, SIGNAL(triggered()), this, SLOT(setItalic()));
//        connect(colorMainWindow, SIGNAL(triggered()), this, SLOT());
        connect(editColor, SIGNAL(triggered()), this, SLOT(setColor()));
        connect(closeApp, SIGNAL(triggered()), this, SLOT(closeapp()));
        connect(closeApp, SIGNAL(triggered()), this, SLOT(closeapp()));

//    connect(showD, SIGNAL(clicked()), this, SLOT(suchka()));
    connect(plus, SIGNAL(clicked()), this, SLOT(plusText()));
    connect(minus, SIGNAL(clicked()), this, SLOT(minusText()));
//    connect(italicBtn, SIGNAL(clicked()), this, SLOT(setItalic()));
//    connect(boldBtn, SIGNAL(clicked()), this, SLOT(setBold()));
//    connect(underlineBtn, SIGNAL(clicked()), this, SLOT(setUnderline()));
//    connect(changeColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(files, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemSelected(QListWidgetItem*)));
    ReadFilesHistory();

    this->labelSizeInterval = new QLabel("Расстояние между строк \n(выделить строчки для работы)", this);
    this->labelSizeInterval->setParent(this);

    this->slider = new QSlider(Qt::Orientation::Horizontal, this);
    this->slider->setMaximum(1);
    this->slider->setMaximum(100);
    this->slider->setGeometry(520, 480, 180,45);
    this->slider->setParent(this);
//int x=0;
    connect(slider, SIGNAL(sliderReleased()), this, SLOT(chooseHeightLine()));
}

void MainWindow::chooseHeightLine(){
//    QMessageBox m;
//    m.exec();
    QTextCursor cur = inputT->textCursor();
    QTextBlockFormat format = cur.blockFormat();
    //прикольная штука
    //format.setLineHeight(20, 1);
    format.setLineHeight(slider->value(), 4);
    cur.setBlockFormat(format);
    inputT->setTextCursor(cur);
}


QVector<QString> MainWindow::convertFromStirngToStringVector(QString str){
        QVector<QString> tmp;

//    for(int i = 0; i < str.length(); i++){
//        if(str.at(i).isLetter())
//            continue;
//        tmp.append( str.left(str.indexOf(" ",i, Qt::CaseInsensitive)));
//        str.remove(tmp.last());
//        tmp.last().replace(" ","");
//        i = 0;
//    }

    QRegExp rx("(\\ |\\,|\\.|\\:|\\t)");
    QStringList ss = str.split(rx);
    foreach (QString i, ss) {
        tmp.append(i);
    }
  return tmp;
}

void MainWindow::checkgramary(){
    QVector<QString> str =  convertFromStirngToStringVector(inputT->toPlainText());
    QVector<QString> dataBase ;
    QString path("/Users/");
    path.append(qUsername);
    path.append("/Documents/dataWordsRussian.txt");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream outStream(&file);
    outStream.setCodec("windows-1251");
    bool isEnableBadWords = false;
    while (!outStream.atEnd()) {
        dataBase.append(outStream.readLine().simplified());
    }
    file.close();

//    for (int i = 0; i < dataBase.count(); i++) {
//        inputT->append( dataBase.at(i) );
//    }
//    QMessageBox m;
//    m.setText(dataBase.at(dataBase.length() - 1));
//            m.exec();
//        if(!dataBase.contains(str.at(0))){

//        QMessageBox m;

//        m.exec();
//        }
    for (int t = 0;t < str.size(); t++) {
//        if(dataBase.contains(str.at(t))){
//            QString searched = str.at(t);
//            QMessageBox m;
//            m.setText(searched);
//                    m.exec();
            int pos = dataBase.indexOf(str.at(t));
            if(pos < 0 || dataBase.at(pos).size() != str.at(t).size()){
                int s = 0;
                QString searched = str.at(t);
                QMessageBox m;
                            m.setText("Слова "+ str.at(t) + " нет");
                                    m.exec();
                 for(int i = 0; i < inputT->toPlainText().size(); i++){
                    s = inputT->toPlainText().indexOf(searched, i);
                                if(s >= 0){

                                    QTextCharFormat fmt = inputT->currentCharFormat();
                                    fmt.setForeground(QBrush(Qt::red));
                                    QTextCursor cursor = inputT->textCursor();
                                    cursor.setPosition(s);
                                    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, searched.size());
                                    cursor.setCharFormat(fmt);
                                    inputT->setFocus();
                                    inputT->setTextCursor(cursor);
                                    isEnableBadWords = true;
                                    i += search->toPlainText().size();

                                    cursor.clearSelection();
                                    inputT->setTextCursor(cursor);
                                }
                 }

            }
    }
    QTextCharFormat fmt = inputT->currentCharFormat();
    fmt.setForeground(QBrush(Qt::white));
    QTextCursor cursor = inputT->textCursor();
    cursor.setPosition(inputT->toPlainText().size() );
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, inputT->toPlainText().size() );
    cursor.setCharFormat(fmt);
    inputT->setTextCursor(cursor);
    if(isEnableBadWords == true)
         hoverOnOff->show();

}

void MainWindow::hoverOnOrOff(){
    QTextCharFormat fmt = inputT->currentCharFormat();
    fmt.setForeground(QBrush(Qt::white));
    QTextCursor cursor = inputT->textCursor();
    cursor.setPosition(0);
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, inputT->toPlainText().size());
    cursor.setCharFormat(fmt);
    inputT->setFocus();
    inputT->setTextCursor(cursor);
    cursor.clearSelection();
    inputT->setTextCursor(cursor);
    hoverOnOff->hide();
    searchAll->setCheckState(Qt::CheckState::Unchecked);
}

void MainWindow::checkRegisterWords(){
    //checkWordRegicst->setTristate(checkWordRegicst->isTristate());
}

void MainWindow::searchWord(){

//    cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 4);
 //   cursor.setPosition(2, QTextCursor::MoveAnchor);
    QString searched = search->toPlainText();
    QString field = inputT->toPlainText();
    if(checkWordRegicst->checkState() == Qt::CheckState::Checked){
       searched = searched.toLower();
       field = field.toLower();
    }
    int s = 0;
    if(searchAll->checkState() == Qt::CheckState::Unchecked){
        s = field.indexOf(searched);

//    int s = inputT->toPlainText().indexOf(search->toPlainText(), Qt::CaseSensitivity::CaseInsensitive);
        if(s >= 0){
            QTextCharFormat fmt = inputT->currentCharFormat();
            fmt.setForeground(QBrush(Qt::red));
            QTextCursor cursor = inputT->textCursor();
            cursor.setPosition(s);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, search->toPlainText().size());
            cursor.setCharFormat(fmt);
            inputT->setFocus();
            inputT->setTextCursor(cursor);
        }
    }else{
        for(int i = 0; i < inputT->toPlainText().size(); i++){
            s = field.indexOf(searched, i);
            if(s >= 0){
                QTextCharFormat fmt = inputT->currentCharFormat();
                fmt.setForeground(QBrush(Qt::red));
                QTextCursor cursor = inputT->textCursor();
                cursor.setPosition(s);
                cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, search->toPlainText().size());
                cursor.setCharFormat(fmt);
                inputT->setFocus();
                inputT->setTextCursor(cursor);

                i += search->toPlainText().size();

                cursor.clearSelection();
                inputT->setTextCursor(cursor);

            }
        }
    }
    hoverOnOff->show();

}

void MainWindow::saveFilesHistory(){
    QString path("/Users/");
    path.append(qUsername);
    path.append("/Documents/history.txt");

    QFile file(path);

        if(file.open(QIODevice::WriteOnly)){
            QTextStream outStream(&file);
            for(int i = 0; i < files->count(); i++){
                outStream << files->item(i)->text();
                outStream << "\n";
            }
        }

    file.close();
}

void MainWindow::ReadFilesHistory(){

    QString path("/Users/");
    path.append(qUsername);
    path.append("/Documents/history.txt");
    QFile file(path);

    if(file.open(QIODevice::ReadOnly)){
        QTextStream outStream(&file);

        QTextStream in(&file);
           while (!in.atEnd()) {
               files->insertItem(1,new QListWidgetItem(in.readLine()));
           }
    }
}

void MainWindow::fromStringToListItem(QString filepath){
    QListWidgetItem *newFile = new QListWidgetItem(files);
    newFile->setText(filepath);
    files->insertItem(1,newFile);
}

void MainWindow::chooseYourFont(){
    bool click;
    QFont font = QFontDialog::getFont(&click, QFont("Helvetica [Cronyx]", 10), this);
    if (click) {
        inputT->setFont(font);
    } else {
       QMessageBox m;
       m.setText("error");
       m.exec();
    }
}

void MainWindow::itemSelected(QListWidgetItem *item){
//    QMessageBox m;
//    m.setText(item->text());
//    m.exec();

    if(QFile::exists(item->text())){
        QFile outputFile(item->text());
        outputFile.open(QIODevice::ReadOnly);
        QTextStream outStream(&outputFile);
        inputT->setText(outStream.readAll());
        outputFile.close();
    }else{

        QMessageBox m;
        m.setText("No such file \nThis path will be delete");
        m.exec();
        files->takeItem(files->row(item));
        files->update();
    }
}

void MainWindow::openFile(){
//    QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(),tr("Document files (*.doc *.rtf *.txt)"), 0, QFileDialog::DontUseNativeDialog);

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Text (*.txt *.doc *rtf)"));

//    dialog.getOpenFileNames(this, tr("open doc"),QDir::currentPath(), tr("Documents (*.doc *.txt *.rtf);;All files(*.*)"));

    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    QStringList fileNames;
    if (dialog.exec()){
        fileNames = dialog.selectedFiles();

        QFile outputFile(fileNames.at(0));
        outputFile.open(QIODevice::ReadOnly);
        QTextStream outStream(&outputFile);
        inputT->setText(outStream.readAll());
        outputFile.close();


    }

}

void MainWindow::closeapp(){
    this->close();
}

//void MainWindow::changeColorMainWindow(){

//    QColorDialog *dialog = new QColorDialog();

//}

void MainWindow::setColor(){
    QColorDialog *dialog = new QColorDialog();
        inputT->setTextColor(dialog->getColor());
}

void MainWindow::setItalic(){
    QFont f(inputT->fontFamily());
    f.setPointSize((fSize));
    f.setItalic(!inputT->font().italic());
    f.setUnderline(inputT->font().underline());
    f.setBold(inputT->font().bold());
    inputT->setFont(f);
    inputT->update();
}

void MainWindow::setBold(){
    QFont f(inputT->fontFamily());
    f.setPointSize((fSize));
    f.setItalic(inputT->font().italic());
    f.setUnderline(inputT->font().underline());
    f.setBold(!inputT->font().bold());
    inputT->setFont(f);
    inputT->update();
}

void MainWindow::setUnderline(){
    QFont f(inputT->fontFamily());
    f.setPointSize(fSize);
    f.setItalic(inputT->font().italic());
    f.setUnderline(!inputT->font().underline());
    f.setBold(inputT->font().bold());
    inputT->setFont(f);
    inputT->update();
}

void MainWindow::plusText(){
    QFont f(inputT->fontFamily());
    fSize ++;
    f.setPointSize(fSize);
    f.setItalic(inputT->font().italic());
    f.setUnderline(inputT->font().underline());
    f.setBold(inputT->font().bold());
    inputT->setFont(f);
    inputT->update();
}

void MainWindow::minusText(){
    QFont f(inputT->fontFamily());
    fSize --;
    f.setPointSize((fSize));
    f.setItalic(inputT->font().italic());
    f.setUnderline(inputT->font().underline());
    f.setBold(inputT->font().bold());
    inputT->setFont(f);
    inputT->update();
}

void MainWindow::save(){

   QFileDialog dialog(this);
   //сохранить диалог
   dialog.setAcceptMode(QFileDialog::AcceptSave);
   //открыть файл
   //dialog.setAcceptMode(QFileDialog::AcceptOpen);
   dialog.setFileMode(QFileDialog::AnyFile);

//   dialog.exec();

QString PATH = dialog.getSaveFileName(this, tr("save doc"),QDir::currentPath(), tr("Documents (*.doc *.txt *.rtf);"));

//QString PATH = dialog.getSaveFileName();
  // if(dialog.exec()){
     if(PATH.size() > 0){
//        QStringList fileNames;
//       fileNames = dialog.selectedFiles();
//       QString allF;
//       for(int i = 0; i < fileNames.length(); i++){
//           allF.append(fileNames.at(i));
//       }

//       QMessageBox listt;
//       listt.setText(dialog.getSaveFileName());
//       listt.exec();

             QFile outputFile(PATH);
             outputFile.open(QIODevice::WriteOnly);

             QTextStream outStream(&outputFile);
             outStream << inputT->toPlainText();
             outputFile.close();
             fromStringToListItem(PATH);


   }
}



MainWindow::~MainWindow()
{
    saveFilesHistory();
    delete ui;
}

