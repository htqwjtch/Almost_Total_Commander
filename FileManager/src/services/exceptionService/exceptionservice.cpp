#include "exceptionservice.h"

ExceptionService::ExceptionService(QString exceptionInfo)
{
    this->exceptionInfo = exceptionInfo;
}

const QString ExceptionService::getInfo() const noexcept
{
    return exceptionInfo;
}
