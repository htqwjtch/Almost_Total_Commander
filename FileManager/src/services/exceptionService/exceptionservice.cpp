#include "exceptionservice.h"

ExceptionService::ExceptionService(QString exceptionTitle, QString exceptionInfo)
{
    this->exceptionTitle = exceptionTitle;
    this->exceptionInfo = exceptionInfo;
}

const QString ExceptionService::getInfo() const noexcept
{
    return exceptionInfo;
}

const QString ExceptionService::getTitle() const noexcept
{
    return exceptionTitle;
}
