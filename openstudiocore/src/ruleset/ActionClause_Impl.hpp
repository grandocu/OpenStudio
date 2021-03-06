/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef RULESET_ACTIONCLAUSE_IMPL_HPP
#define RULESET_ACTIONCLAUSE_IMPL_HPP

#include <ruleset/RulesetAPI.hpp>
#include <ruleset/Clause_Impl.hpp>

class QDomElement;
class QDomDocument;

namespace openstudio {
namespace ruleset {

class ActionClause;
class FilterClause;

namespace detail {

  class RULESET_API ActionClause_Impl : public Clause_Impl {

    Q_OBJECT;

   public:
    /** @name Constructors and Destructors */
    //@{

    ActionClause_Impl();

    ActionClause_Impl(const UUID& uuid, const UUID& versionUUID);

    ActionClause_Impl(const QDomElement& element);
    
    virtual ~ActionClause_Impl() {}

    //@}
    /** @name Getters */
    //@{

    //@}
    /** @name Serialization */
    //@{

    virtual void writeValues(QDomDocument& doc, QDomElement& element) const;

    //@}
    /** @name Queries */
    //@{

    /** Equality as determined by deep comparison of data members. */
    virtual bool equivalentData(const RulesetObject& other) const;

    //@}
   private:
    REGISTER_LOGGER("Ruleset.ActionClause");
  };

} // detail

} // ruleset
} // openstudio

#endif // RULESET_ACTIONCLAUSE_IMPL_HPP
