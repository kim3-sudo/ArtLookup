#include <string>

using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

//I'm not sure if I like using a struct here - Ryan
struct MemberInfo{
  string m_email;
  string m_password;
  string m_username;
};

class Member{
public:
  Member();
  Member(string email, string password, string username);
  void like(int objectId, string objectType);
  void comment(int objectId, string objectType, string comment);
  bool isValidMember();
private:
  MemberInfo info;
};

#endif
