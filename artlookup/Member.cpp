//File Name: Member.cpp
//Author: Ryan, Michaela, and Sejin
//Email Address: schultz4@kenyon.edu, kim3@kenyon.edu, brydon1@kenyon.edu
//Assignment: Project 3
//Description: Class describing functionality and characteristics of member
//Last Changed: November 21, 2019

#include "Member.h"

Member::Member(){
	//m_memberId = 0;
    m_username = "";
    m_password = "";
    m_email = "";
}

// I want to not input a memberId
//Member::Member(string memberId, string username, string password, string email){
Member::Member(string username, string password, string email){
	//m_memberId = memberId;
    m_username = username;
    m_password = password;
    m_email = email;
}

Member::Member(const Member& otherMember){
    m_username = otherMember.m_username;
    m_password = otherMember.m_password;
    m_email = otherMember.m_email;
}

string Member::getUsername(){
	return m_username;
}
string Member::getPassword(){
	return m_password;
}
string Member::getEmail(){
	return m_email;
}

// void Member::likeArtwork(Artwork artwork){
// }
// //void Member::likeComment(Comment comment);
// void Member::commentOnArtwork(string comment, Artwork artwork){

// }





