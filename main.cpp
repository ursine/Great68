#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

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

    // A boolean option with multiple values (-v)
    QCommandLineOption vbs ( QStringList() << "v" << "verbose",
                QCoreApplication::translate("main", "Show verbose logging about the system") );
    parser.addOption(vbs);

    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    const bool verbose = parser.isSet(vbs);





    return app.exec();
}
