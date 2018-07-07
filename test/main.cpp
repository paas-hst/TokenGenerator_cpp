/**
 * build with command:
 * g++ main.cpp  ../src/aes.cpp -I../src -std=c++11
 */

#include <cstdint>
#include <iostream>

#include "fsp_token.h"

int main(int argc, char const *argv[]) {

  std::string appID = "testappid";
  std::string appSecretKey = "1234567890123456";

  fsp::tools::AccessToken token(appSecretKey);

  token.app_id = appID;
  token.group_id = "group1";
  token.user_id = "user1";
  token.expire_time = 0;

  std::string strToken = token.Build();

  std::cout << strToken << std::endl;

  fsp::tools::AccessToken token1(appSecretKey);
  std::string parsedJson = token1.ParseToJson(strToken);

  std::cout << "parse json:" << parsedJson << std::endl;

  return 0;
}
