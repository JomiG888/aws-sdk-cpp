﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/appconfig/model/DeploymentEvent.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace AppConfig
{
namespace Model
{

DeploymentEvent::DeploymentEvent() : 
    m_eventType(DeploymentEventType::NOT_SET),
    m_eventTypeHasBeenSet(false),
    m_triggeredBy(TriggeredBy::NOT_SET),
    m_triggeredByHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_occurredAtHasBeenSet(false)
{
}

DeploymentEvent::DeploymentEvent(JsonView jsonValue) : 
    m_eventType(DeploymentEventType::NOT_SET),
    m_eventTypeHasBeenSet(false),
    m_triggeredBy(TriggeredBy::NOT_SET),
    m_triggeredByHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_occurredAtHasBeenSet(false)
{
  *this = jsonValue;
}

DeploymentEvent& DeploymentEvent::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("EventType"))
  {
    m_eventType = DeploymentEventTypeMapper::GetDeploymentEventTypeForName(jsonValue.GetString("EventType"));

    m_eventTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("TriggeredBy"))
  {
    m_triggeredBy = TriggeredByMapper::GetTriggeredByForName(jsonValue.GetString("TriggeredBy"));

    m_triggeredByHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Description"))
  {
    m_description = jsonValue.GetString("Description");

    m_descriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("OccurredAt"))
  {
    m_occurredAt = jsonValue.GetString("OccurredAt");

    m_occurredAtHasBeenSet = true;
  }

  return *this;
}

JsonValue DeploymentEvent::Jsonize() const
{
  JsonValue payload;

  if(m_eventTypeHasBeenSet)
  {
   payload.WithString("EventType", DeploymentEventTypeMapper::GetNameForDeploymentEventType(m_eventType));
  }

  if(m_triggeredByHasBeenSet)
  {
   payload.WithString("TriggeredBy", TriggeredByMapper::GetNameForTriggeredBy(m_triggeredBy));
  }

  if(m_descriptionHasBeenSet)
  {
   payload.WithString("Description", m_description);

  }

  if(m_occurredAtHasBeenSet)
  {
   payload.WithString("OccurredAt", m_occurredAt.ToGmtString(DateFormat::ISO_8601));
  }

  return payload;
}

} // namespace Model
} // namespace AppConfig
} // namespace Aws
