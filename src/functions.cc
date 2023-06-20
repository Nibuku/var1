#include <functions.h>
#include "functions.h"




unique_ptr<Account> Settlement::clone() const
{
    return unique_ptr<Account>();
}

bool Settlement::equals(shared_ptr<Account>) const
{
    return false;
}

void Settlement::print(ostream& out) const
{
}
