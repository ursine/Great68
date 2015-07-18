#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QByteArray>
#include <QtGlobal>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Those Darn Geeks");
    QCoreApplication::setOrganizationDomain("thosedarngeeks.com");
    QCoreApplication::setApplicationName("Great68");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("An emulator for the Tandy Color Computers and accessories");
    parser.addHelpOption();
    parser.addVersionOption();
    
    /*parser.addOptions({
                      { {"V","verbose"},
                          QCoreApplication::translate("main", "Show verbose logging about the system")},
                          });        */

    parser.addPositionalArgument("basic-rom","The color computer basic rom to load at $A000");
    
    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    //const bool verbose = parser.isSet("verbose");

    const QString brom = args.isEmpty() ? "" : args.first();    
    
    QFile romFile(brom);
    const QFileInfo romInfo(romFile);
    
    qDebug() << "Loading ROM: " << romInfo.absoluteFilePath();

    QByteArray ram(64*1024,0);

    size_t loadLoc = 0xA000;
    
    if (!romFile.open(QIODevice::ReadOnly))
    {
      qCritical("Unable to open rom file");      
    }

    char buffer[1024];
    while(qint64 bytesRead = romFile.read(buffer,sizeof(buffer)))
    {
      if (bytesRead==-1) {
        qCritical("Unable to complete reading file");
        break;
      }
      
      ram.replace(loadLoc,bytesRead,buffer,bytesRead);
      qDebug("Read %d bytes to %x - %x",bytesRead,loadLoc,loadLoc+bytesRead-1);
      loadLoc += bytesRead;
      
    }
    
    return app.exec();
}
