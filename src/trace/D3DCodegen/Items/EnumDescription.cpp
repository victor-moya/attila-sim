/**************************************************************************
 *
 * Copyright (c) 2002 - 2011 by Computer Architecture Department,
 * Universitat Politecnica de Catalunya.
 * All rights reserved.
 *
 * The contents of this file may not be disclosed to third parties,
 * copied or duplicated in any form, in whole or in part, without the
 * prior permission of the authors, Computer Architecture Department
 * and Universitat Politecnica de Catalunya.
 *
 */

////////////////////////////////////////////////////////////////////////////////

#include "Items/EnumDescription.hpp"

using namespace std;
using namespace dxcodegen::Items;

////////////////////////////////////////////////////////////////////////////////

void EnumDescription::SetName(const string& name)
{
  m_name = name;
}

////////////////////////////////////////////////////////////////////////////////

string& EnumDescription::GetName()
{
  return m_name;
}

////////////////////////////////////////////////////////////////////////////////

bool EnumDescription::AddMember(const EnumDescriptionMember& member)
{
  pair<string,string> ins_elem(member.name, member.name);
  pair<map<string,string>::iterator, bool> ins_res;
  ins_res = m_mapMembers.insert(ins_elem);
  if (ins_res.second)
  {
    m_lstMembers.push_back(member);
    return true;
  }
  return false;
}

////////////////////////////////////////////////////////////////////////////////

unsigned int EnumDescription::GetMembersCount()
{
  return (unsigned int) m_lstMembers.size();
}

////////////////////////////////////////////////////////////////////////////////

EnumDescriptionMember& EnumDescription::GetMember(unsigned int position)
{
  static EnumDescriptionMember member;
  if (m_lstMembers.size() && position < m_lstMembers.size())
  {
    return m_lstMembers[position];
  }
  return member;
}

////////////////////////////////////////////////////////////////////////////////
