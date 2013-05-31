#ifndef PRJREADER_H
#define PRJREADER_H

#include <QTextStream>
#include <QStringList>
#include <utilities/core/Logger.hpp>

namespace openstudio {
namespace contam {
namespace prj {

class Reader
{
public:
    explicit Reader(QTextStream *stream);
    explicit Reader(QString string, int starting=0);
    ~Reader();
    float readFloat();
    double readDouble();
    QString readString();
    int readInt();
    QString readLine();
    void read999();
    void readEnd();
    void skipSection();
    QString storeSection();
    int lineNumber(){return m_lineNumber;}
    QList<int> readIntArray(bool terminated=false);
    template <class T> QList<T> readSection();
    template <class T> T readNumber();


private:
    QTextStream *stream;
    int m_lineNumber;
    bool allocated;
    QStringList entries;

    REGISTER_LOGGER("openstudio.contam.prj.Reader");
};

template <class T> QList<T> Reader::readSection()
{
    QList<T> list;
    int n = readInt();
    for(int i=0;i<n;i++)
    {
        T object;
        object.read(this);
        list << object;
    }
    read999();
    return list;
}

}
}
}

#endif // PRJREADER_H