#include"Utils.hpp"

std::string Utils::validInput(std::string value)
{
  const std::string whiteSpace = " \n\r\t\f\v";
  std::string leftTrim;
  int end;

  if(value.empty())
 	return false;
  leftTrim = value.substr(value.find_first_not_of(whiteSpace));

  std::string rightTrim = leftTrim.substr(0, find_last_not_of(whiteSpace)+1);
  if(rightTrim.length() == 0)
	return NULL;
  return rightTrim ;
}
