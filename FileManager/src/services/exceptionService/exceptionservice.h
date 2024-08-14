#ifndef EXCEPTIONSERVICE_H
#define EXCEPTIONSERVICE_H

#include <QString>

class ExceptionService
{
    QString exceptionTitle = "";
    QString exceptionInfo = "Something went wrong";

public:
    ExceptionService() = default;
    ExceptionService(QString exceptionTitle, QString exceptionInfo);
    const QString getTitle() const noexcept;
    const QString getInfo() const noexcept;
};

#endif // EXCEPTIONSERVICE_H
