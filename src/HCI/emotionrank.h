#ifndef EMOTIONRANK_H
#define EMOTIONRANK_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>

class EmotionRank: public QWidget{
    Q_OBJECT

public:
    EmotionRank(QString em="", QWidget *p=0);
private:
    QList<QRadioButton*> radios;

};

#endif
