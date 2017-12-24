#include <QCoreApplication>
#include "../../QEasyDownloader.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    /*
     * Construct
    */
    QEasyDownloader Downloader;

    /*
     * By Default Debug is false , make it true to print the download progress and
     * other stuff!
    */
    Downloader.Debug(true);

    /*
     * By Default auto Resuming of Downloads is true.
     *
     * You can also disable auto resuming of downloads.
     * But I strongly recommend you don't!
    */
    // Downloader.ResumeDownloads(false);

    /*
     * Connect Callbacks!
    */
    QObject::connect(&Downloader, &QEasyDownloader::GetResponse,
    [&](QString resp) {
        qDebug() << "My Response:: "<< resp;
        app.quit();
    });

    /*
     * Just Download!
    */
    Downloader.Get(QUrl("http://icanhazip.com"));
    return app.exec();
}