/*
 *  Copyright (c) 2000 - 2013 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Contact: Bumjin Im <bj.im@samsung.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License
 */
/*
 * @file        get-object-name.h
 * @author      Jan Olszak (j.olszak@samsung.com)
 * @version     1.0
 * @brief       Implementation of api-get-object-name service.
 */

#ifndef _SECURITY_SERVER_SERV_GET_OBJECT_NAME_
#define _SECURITY_SERVER_SERV_GET_OBJECT_NAME_

#include <service-thread.h>
#include <generic-socket-manager.h>

#include <dpl/serialization.h>
#include <message-buffer.h>

#include <security-server-common.h>

namespace SecurityServer {

class GetObjectNameService  :
    public SecurityServer::GenericSocketService
  , public SecurityServer::ServiceThread<GetObjectNameService>
{
public:
    typedef std::map<int, MessageBuffer> MessageBufferMap;

    ServiceDescriptionVector GetServiceDescription();

    DECLARE_THREAD_EVENT(AcceptEvent, accept)
    DECLARE_THREAD_EVENT(WriteEvent, write)
    DECLARE_THREAD_EVENT(ReadEvent, read)
    DECLARE_THREAD_EVENT(CloseEvent, close)

    void accept(const AcceptEvent &event);
    void write(const WriteEvent &event);
    void read(const ReadEvent &event);
    void close(const CloseEvent &event);

private:
    std::string m_name;
    bool readOne(const ConnectionID &conn, MessageBuffer &buffer);
    int  setName(gid_t gid);
    MessageBufferMap m_messageBufferMap;
};

} // namespace SecurityServer

#endif // _SECURITY_SERVER_SERV_GET_OBJECT_NAME_
