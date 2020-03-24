#include "postfix.h"
#include "stack.h"
/*
bool TPostfix::isCorrect(string str)
{
  string unacceptable = "!@#^&.,<>{}[]|=_?";
  int count = 0, k = 0, countOperation = 0, length = str.length();
  if ((operands.find(str[0]) != string::npos) || (operands.find(str[length - 1]) != string::npos))
    return false;
  for (int i = 0; i < length; i++)
  {
    if (unacceptable.find(str[i]) != string::npos)
      return false;
    if (str[i] == '(')
      count++;
    if (str[i] == ')')
      count--;
    if ((str[i] - 'a' >= 0) && (str[i] - 'a' <= 26))
      k++;
    else
      k = 0;
    if (operands.find(str[i]) != string::npos)
      countOperation++;
    else
      countOperation = 0;
    if ((k > 1) || (countOperation > 1))
      return false;
  }
  if (count != 0)
    return false;
  return true;
}

string TPostfix::ToPostfix()
{
  TStack<char> opStack(MaxStackSize);
  string tmp = "+-/*()";  // обратно поменять местами * и /
  int length = infix.length();
  for (int i = 0; i < length; i++)
  {
    if (tmp.find(infix[i]) == string::npos)
      postfix += infix[i];
    if ((infix[i] >= '0') && (infix[i] <= '9'))
      if (i != length)
      {
        if ((infix[i + 1] < '0') || (infix[i + 1] > '9'))
          postfix += '>';
      }
      else
        postfix += '>';
    if (infix[i] == '(')
      opStack.push(infix[i]);
    if (infix[i] == ')')
    {
      char temp = opStack.pop();
      while (temp != '(')
      {
        postfix += temp;
        temp = opStack.pop();
      }
    }
    if (operands.find(infix[i]) != string::npos)
    {
      if (opStack.empty())
        opStack.push(infix[i]);
      else
      {
        int index2 = operands.find(infix[i]);
        while (!opStack.empty())
        {
          char temp = opStack.pop();
          if (temp == '(')
          {
            opStack.push(temp);
            break;
          }
          int index1 = operands.find(temp);
          if (priority[index2] <= priority[index1])
            postfix += temp;
          else
          {
            opStack.push(temp);
            break;
          }
        }
        opStack.push(infix[i]);
      }
    }
  }
  while (!opStack.empty())
  {
    postfix += opStack.pop();
  }
  return postfix;
}
*/