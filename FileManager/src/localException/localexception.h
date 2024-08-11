#ifndef LOCALEXCEPTION_H
#define LOCALEXCEPTION_H

#include <QString>

class LocalException
{
    QString exceptionTitle = "";
    QString exceptionInfo = "\nSomething went wrong\n";

public:
    LocalException(QString exceptionTitle, QString exceptionInfo)
    {
	this->exceptionTitle = exceptionTitle;
	this->exceptionInfo = exceptionInfo;
    }
    const QString get_title() const noexcept
    {
	return exceptionTitle;
    }
    const QString get_info() const noexcept
    {
	return exceptionInfo;
    }
};

#endif // LOCALEXCEPTION_H
