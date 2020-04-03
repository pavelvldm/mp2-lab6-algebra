#include "postfix.h"
#include "stack.h"

bool TPostfix::isCorrect(string str)
{
  string unacceptable = "!@#^&.,<>{}[]|=_?";
  int count = 0, countOperation = 0, length = str.length();
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
    if (operands.find(str[i]) != string::npos)
      countOperation++;
    else
      countOperation = 0;
    if (countOperation > 1)
      return false;
  }
  if (count != 0)
    return false;
  return true;
}

string TPostfix::ToPostfix()
{
  TStack<char> opStack(MaxStackSize);
  string tmp = "+-*/()";  
  int length = infix.length();
  int check = -1;
  for (int i = 0; i < length; i++)
  {
      if (tmp.find(infix[i]) == string::npos) {
            //   if (tmp.find(infix[i]) == string::npos)
              postfix += infix[i];
              check = 1;
              if ((infix[i] >= '0') && (infix[i] <= '9'))
              {
                  if (i != length)
                  {
                      if ((infix[i + 1] < '0') || (infix[i + 1] > '9'))
                          postfix += '>';
                  }
                  else
                      postfix += '>';
                  check = 0;
              }
      }
      else 
      {
          if (check != 0 && check != -1)
          {
              postfix += '|';
              check = -1;
          }
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
          if (operands.find(infix[i]) != string::npos) //если найдено
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
      if( i == length-1)
          if (check != 0 && check != -1)
              postfix += '|';
  }
  while (!opStack.empty())
  {
    postfix += opStack.pop();
  }
  return postfix;
}
double TPostfix::Calculate(ordered_line_table tab)
{
    if (postfix.length() == 0)
        ToPostfix();
    int len = postfix.length();
    TStack<double> res(MaxStackSize);
    vector <string> name_val;
    int size_vector = 0;
    string name;
    double* val = new double[len];
    int x, y, z;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "z: ";
    cin >> z;
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        if (operands.find(postfix[i]) == string::npos)
        {
            double p;
            if ((postfix[i] < 48) || (postfix[i] > 57))
            {
                while (postfix[i] != '|')
                {
                    name += postfix[i];
                    i++;
                }
                if (size_vector != 0)
                {
                    int r = 0;
                    for (; r < size_vector; r++)
                    {
                        if (name_val[r] == name)
                        {
                            p = tab.Find(name)->Poly.ValuePoint(x, y, z);
                            break;
                        }
                    }
                    if (r == size_vector)
                    {
                        name_val.push_back(name);
                        size_vector = name_val.size();
                        if (tab.Find(name) != nullptr)
                            p = tab.Find(name)->Poly.ValuePoint(x, y, z);
                        else
                            throw 2;
                        val[size_vector - 1] = p;
                    }
                }
                else
                {
                    name_val.push_back(name);
                    size_vector = name_val.size();
                    if (tab.Find(name) != nullptr)
                        p = tab.Find(name)->Poly.ValuePoint(x, y, z);
                    else
                        throw 2;
                    val[size_vector - 1] = p;
                }         
                name = "";
            }
            else
            {
                string number;
                while (postfix[i] != '>')
                {
                    number += postfix[i];
                    i++;
                }
                p = stoi(number);
            }
            res.push(p);
        }
        else
        {
            double val1, val2, val3;
            val2 = res.pop();
            val1 = res.pop();
            switch (postfix[i])
            {
            case '+': val3 = val1 + val2; break;
            case '-': val3 = val1 - val2; break;
            case '*': val3 = val1 * val2; break;
            case '/': val3 = val1 / val2; break;
            }
            res.push(val3);
        }
    }
    delete[] val;
    return res.pop();
}