#include <cstdio>
#include <stack>
#include <string>

bool isValid(std::string s)
{
  std::stack<char> cache;

  std::string::iterator it = s.begin(),
                        end = s.end();
  for (; it != end; ++it)
  {
    if (*it == '(' || *it == '{' || *it == '[')
    {

      cache.push(*it);
    }
    else if (*it == ')' || *it == '}' || *it == ']')
    {
      if (!cache.empty() && ((cache.top() == '(' && *it == ')') ||
                            (cache.top() == '{' && *it == '}') ||
                            (cache.top() == '[' && *it == ']')))
      {
        cache.pop();
      }
      else
      {
        return false;
      }
    }
  }

  return cache.empty();
}

int main(void)
{
  //
  if (isValid("let s = [1,2,3,4]; if(s.length <= 0) { console.log('empty'); }"))
  {
    printf("valid");
  }
  else
  {
    printf("invalid");
  }
}
