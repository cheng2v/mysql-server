/* Copyright (C) 2003 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#include <signaldata/CreateTrigImpl.hpp>
#include <trigger_definitions.h>

bool
printCREATE_TRIG_IMPL_REQ(FILE* output, const Uint32* theData, Uint32 len, Uint16)
{
  const CreateTrigImplReq* sig = (const CreateTrigImplReq*)theData;
  const Uint32 triggerType =
    TriggerInfo::getTriggerType(sig->triggerInfo);
  const Uint32 triggerActionTime =
    TriggerInfo::getTriggerActionTime(sig->triggerInfo);
  const Uint32 triggerEvent =
    TriggerInfo::getTriggerEvent(sig->triggerInfo);
  const Uint32 monitorReplicas =
    TriggerInfo::getMonitorReplicas(sig->triggerInfo);
  const Uint32 monitorAllAttributes =
    TriggerInfo::getMonitorAllAttributes(sig->triggerInfo);
  const Uint32 reportAllMonitoredAttributes =
    TriggerInfo::getReportAllMonitoredAttributes(sig->triggerInfo);
  fprintf(output, " senderRef: 0x%x", sig->senderRef);
  fprintf(output, " senderData: %u", sig->senderData);
  fprintf(output, " requestType: %u", sig->requestType);
  fprintf(output, "\n");  
  fprintf(output, " tableId: %u", sig->tableId);
  fprintf(output, " tableVersion: 0x%x", sig->tableVersion);
  fprintf(output, " indexId: %u", sig->indexId);
  fprintf(output, " indexVersion: 0x%x", sig->indexVersion);
  fprintf(output, " triggerNo: %u", sig->triggerNo);
  fprintf(output, "\n");  
  fprintf(output, " triggerId: %u", sig->triggerId);
  fprintf(output, " triggerInfo: 0x%x", sig->triggerInfo);
  fprintf(output, "\n");
  fprintf(output, "   triggerType: %u [%s]",
                  triggerType,
                  TriggerInfo::triggerTypeName(triggerType));
  fprintf(output, "\n");
  fprintf(output, "   triggerActionTime: %u [%s]",
                  triggerActionTime,
                  TriggerInfo::triggerActionTimeName(triggerActionTime));
  fprintf(output, "\n");
  fprintf(output, "   triggerEvent: %u [%s]",
                  triggerEvent,
                  TriggerInfo::triggerEventName(triggerEvent));
  fprintf(output, "\n");
  fprintf(output, "   monitorReplicas: %u",
                  monitorReplicas);
  fprintf(output, "\n");
  fprintf(output, "   monitorAllAttributes: %u",
                  monitorAllAttributes);
  fprintf(output, "\n");
  fprintf(output, "   reportAllMonitoredAttributes: %u",
                  reportAllMonitoredAttributes);
  fprintf(output, " receiverRef: 0x%x", sig->receiverRef);
  fprintf(output, "\n");  
  char buf[MAXNROFATTRIBUTESINWORDS * 8 + 1];
  fprintf(output, " attributeMask: %s", sig->attributeMask.getText(buf));
  fprintf(output, "\n");  
  return true;
}

bool
printCREATE_TRIG_IMPL_CONF(FILE* output, const Uint32* theData, Uint32 len, Uint16)
{
  const CreateTrigImplConf* sig = (const CreateTrigImplConf*)theData;
  fprintf(output, " senderRef: 0x%x", sig->senderRef);
  fprintf(output, " senderData: %u", sig->senderData);
  fprintf(output, "\n");  
  fprintf(output, " tableId: %u", sig->tableId);
  fprintf(output, " triggerId: %u", sig->triggerId);
  fprintf(output, " triggerInfo: 0x%x", sig->triggerInfo);
  fprintf(output, "\n");  
  return true;
}

bool
printCREATE_TRIG_IMPL_REF(FILE* output, const Uint32* theData, Uint32 len, Uint16)
{
  const CreateTrigImplRef* sig = (CreateTrigImplRef*)theData;
  fprintf(output, " senderRef: 0x%x", sig->senderRef);
  fprintf(output, " senderData: %u", sig->senderData);
  fprintf(output, "\n");  
  fprintf(output, " tableId: %u", sig->tableId);
  fprintf(output, " triggerId: %u", sig->triggerId);
  fprintf(output, " triggerInfo: 0x%x", sig->triggerInfo);
  fprintf(output, "\n");  
  fprintf(output, " errorCode: %u", sig->errorCode);
  fprintf(output, " errorLine: %u", sig->errorLine);
  fprintf(output, " errorNodeId: %u", sig->errorNodeId);
  fprintf(output, " masterNodeId: %u", sig->masterNodeId);
  fprintf(output, "\n");  
  return true;
}
