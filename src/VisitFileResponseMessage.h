/* This file is part of RTags.

   RTags is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   RTags is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with RTags.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef VisitFileResponseMessage_h
#define VisitFileResponseMessage_h

#include <rct/Message.h>
#include <rct/String.h>
#include "ClientMessage.h"

class VisitFileResponseMessage : public ClientMessage
{
public:
    enum { MessageId = VisitFileResponseId };

    VisitFileResponseMessage(uint32_t fileId = 0, const Path &resolved = Path(), bool visit = false)
        : ClientMessage(MessageId), mFileId(fileId), mResolved(resolved), mVisit(visit)
    {
    }

    uint32_t fileId() const { return mFileId; }
    Path resolved() const { return mResolved; }
    bool visit() const { return mVisit; }

    void encode(Serializer &serializer) const { serializer << mFileId << mResolved << mVisit; }
    void decode(Deserializer &deserializer) { deserializer >> mFileId >> mResolved >> mVisit; }
private:
    uint32_t mFileId;
    Path mResolved;
    bool mVisit;
};

#endif
