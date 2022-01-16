#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QList>

//bool mFirstClick=true;
//bool mPaintFlag=true;
int lineCount=0;
QPoint pointPairs(int,int);
bool za_crtanje;
int tempx;
int tempy;
int i,j,k;
int temp2y;
int temp2x;
int velicina=100;

class MyMainWindow : public QMainWindow {
public:

MyMainWindow();
QLabel* MyLabel;
//void mousePressEvent(QMouseEvent *event) override;
void keyPressEvent(QKeyEvent *event) override;
void paintEvent(QPaintEvent *event) override;
void mousePressEvent(QMouseEvent *event) override;
//void drawLines(QPaintEvent *event, int p);
QMenu* EditMenu;
//QAction* Crtanje;
QAction* EditNoviTekst;
QAction* EditCrtanje;
void EditNoviTekstMenu();
void EditCrtanjeMenu();
//void CrtanjeMenu();
void FileSaveAsMenu();
void FileOpenMenu();
QMenu* FileMenu;
QAction* FileSaveAs;
QAction* FileOpen;
//virtual void setVisible(bool visible);



    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;
    int tempoX;
    int tempoY;

    bool mFirstClick;
    bool mPaintFlag;

protected:

};

void MyMainWindow :: mousePressEvent(QMouseEvent * e)
{
    if(za_crtanje){

    if(e->button() == Qt::LeftButton)
        lineCount++;
    {
        //store 1st point
        if(mFirstClick)
        {

            tempx=mEndX;
            tempy=mEndY;
            mStartX = e->x();
            mStartY = e->y();
            mPaintFlag=true;
            mFirstClick = false;
         //   mPaintFlag=false;
            update ();
        }
        //Mouse Pressed Again! 2nd point
        else if(!mFirstClick)
        {
            temp2x=mStartX;
            temp2y=mStartY;
            mEndX = e->x();
            mEndY = e->y();
            mFirstClick = true;
            mPaintFlag = true;


            update();

        }
    }
}};


int main(int argc, char **argv) {
QApplication app (argc, argv);

MyMainWindow mainWindow;
mainWindow.resize(300,150);
mainWindow.show();
return app.exec();

}




MyMainWindow::MyMainWindow() {
MyLabel = new QLabel(this);
MyLabel->setText("Hello World!");
MyLabel->move(10, 20);

//Crtanje = new QAction(tr("&crtanje"), this);
//EditNoviTekst->setShortcut(tr("CTRL+K"));
//connect(Crtanje, &QAction::triggered, this,
//&MyMainWindow::CrtanjeMenu);

EditNoviTekst = new QAction(tr("&Novi tekst..."), this);
EditNoviTekst->setShortcut(tr("CTRL+N"));
connect(EditNoviTekst, &QAction::triggered, this,
&MyMainWindow::EditNoviTekstMenu);
EditMenu = menuBar()->addMenu(tr("&Edit"));
EditMenu->addAction(EditNoviTekst);

EditCrtanje = new QAction(tr("&Crtanje"), this);
EditCrtanje->setShortcut(tr("CTRL+L"));
connect(EditCrtanje, &QAction::triggered,this,&MyMainWindow::EditCrtanjeMenu);
EditMenu->addAction(EditCrtanje);


FileSaveAs = new QAction(tr("&Save As..."), this);
FileSaveAs->setShortcut(tr("CTRL+S"));
connect(FileSaveAs, &QAction::triggered, this,
&MyMainWindow::FileSaveAsMenu);
FileOpen = new QAction(tr("&Open..."), this);
FileOpen->setShortcut(tr("CTRL+O"));
connect(FileOpen, &QAction::triggered, this,
&MyMainWindow::FileOpenMenu);
FileMenu = menuBar()->addMenu(tr("&File"));
FileMenu->addAction(FileSaveAs);
FileMenu->addAction(FileOpen);


}
//
//void MyMainWindow::mousePressEvent(QMouseEvent* event) {
//if (event->button() == Qt::LeftButton) {

//QMessageBox msgBox;
//msgBox.setText("Prozor je kliknut!");
//msgBox.exec();
//}
//}

//":"2.2*/

//void MyMainWindow::mousePressEvent(QMouseEvent* event) {
//if (event->button() == Qt::LeftButton) {
//MyLabel->move(int(event->position().x()),
//int(event->position().y()));
//}
//}


class MyDialog : public QDialog {
public:
MyDialog();
QVBoxLayout* mainLayout;
QWidget* editWidget;
QFormLayout* editLayout;
QLineEdit* lineEdit;
QDialogButtonBox* buttonBox;
};

MyDialog::MyDialog() {
lineEdit = new QLineEdit;
editLayout = new QFormLayout;
editLayout->addRow(new QLabel(tr("Novi tekst:")), lineEdit);
editWidget = new QWidget;
editWidget->setLayout(editLayout);
buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
QDialogButtonBox::Cancel);
connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
mainLayout = new QVBoxLayout;
mainLayout->addWidget(editWidget);
mainLayout->addWidget(buttonBox);
setLayout(mainLayout);
setWindowTitle("Promjena teksta");
}
//&

void MyMainWindow::EditCrtanjeMenu() {
za_crtanje=true;

}

void MyMainWindow::EditNoviTekstMenu() {
MyDialog dialog;
int ret = dialog.exec();
if( ret == QDialog::Accepted ) {
MyLabel->setText(dialog.lineEdit->text());
}
}

//void MyMainWindow::CrtanjeMenu()  {

//}

void MyMainWindow::keyPressEvent(QKeyEvent *event) {
switch( event->key() ){
case Qt::Key_Left: MyLabel->move(MyLabel->pos().x()-1,
MyLabel->pos().y());
break;
case Qt::Key_Right: MyLabel->move(MyLabel->pos().x()+1,
MyLabel->pos().y());
break;
case Qt::Key_Up: MyLabel->move(MyLabel->pos().x(),
MyLabel->pos().y()-1);
break;
case Qt::Key_Down: MyLabel->move(MyLabel->pos().x(),
MyLabel->pos().y()+1);
break;
}
}
//crtanje linija */

void MyMainWindow::paintEvent(QPaintEvent* e){
         //   MyMainWindow::paintEvent(e);
   // if(za_crtanje){
    if(mPaintFlag)
    {
        for(i=0; i<velicina; ++i){
            for(j=0;j<velicina;++j){
             for(k=0;k<velicina;++k){


        QPainter painter(this);
        QPen paintpen(Qt::red);
        paintpen.setWidth(8);
        QPen bpaintpen(Qt::green);
        bpaintpen.setWidth(8);

        QPen linepen(Qt::black);
        linepen.setWidth(4);
        QPoint p[i];
        QPoint p2[j];
        QPoint p3[k];
        p[i].setX(mStartX);
        p[i].setY(mStartY);
      //  p2.setX(mStartX);
       // p2.setY(mStartY);

        painter.setPen(paintpen);
        painter.drawPoint(p[i]);
      //  painter.drawPoint(p2);
       // painter.drawLine(p2, p1);


        p2[j].setX(mEndX);
        p2[j].setY(mEndY);

        painter.setPen(bpaintpen);
        painter.drawPoint(p2[j]);

        painter.setPen(linepen);
        painter.drawLine(p[i], p2[j]);


        p3[k].setX(tempx);
        p3[k].setY(tempy);


        painter.setPen(linepen);
        painter.drawLine(p3[k], p[i]);
        QPoint p4;
        p4.setX(temp2x);
        p4.setY(temp2y);
        painter.setPen(paintpen);
        painter.drawPoint(p4);
        painter.setPen(linepen);
        painter.drawLine(p3[k], p4);


     //   painter.drawLines(p5 ,lineCount);

        i=i+1;j=j+1;k=k+1;
        void show();
           //     i++;
        //painter.drawLines(p1,lineCount);
   //     void setVisible(bool visible);


}}
       }}}



//void MyMainWindow::drawLines(const QPoint* pointPairs, int lineCount)
//snimanje u datoteku*/

void MyMainWindow::FileSaveAsMenu(){
QString fileName = QFileDialog::getSaveFileName(this, "Save As...", "", "FESB File (*.fsb)");
if (!fileName.isEmpty()) {
QFile file(fileName);
if (!file.open(QIODevice::WriteOnly)) {
QMessageBox::information(this,
"Unable to Open File", file.errorString());
return;
}
QTextStream out(&file);
out << "fesb file" << Qt::endl;
out << MyLabel->text() << Qt::endl;
out << MyLabel->pos().x() << Qt::endl;
out << MyLabel->pos().y() << Qt::endl;
out << pos().x() << Qt::endl;
out << pos().y() << Qt::endl;
out << size().width() << Qt::endl;
out << size().height() << Qt::endl;
}
}

void MyMainWindow::FileOpenMenu(){
QString fileName = QFileDialog::getOpenFileName(this,
"Open Geometry...", "", "FESB File (*.fsb)");
if (!fileName.isEmpty()) {
QFile file(fileName);
if (!file.open(QIODevice::ReadOnly)) {
QMessageBox::information(this, "Unable to Open File", file.errorString());
return;
}
QTextStream in(&file);
QString str; str = in.readLine();
if(str=="fesb file") {
str = in.readLine();
MyLabel->setText(str);
int x, y, w, h;
in >> x >> y;
MyLabel->move(x, y);
in >> x >> y >> w >> h;
this->setGeometry(x, y, w, h);
}
}
}
