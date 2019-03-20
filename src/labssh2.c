/*
 * LabSSH2 - A LabVIEW-Friendly C library for libssh2
 *
 * Copyright (c) 2018 Field R&D Services, LLC. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * withoutmodification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the Field R&D Services nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Field R&D Services, LLC ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Field R&D Services, LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributor(s):
 *   Christopher R. Field <chris@fieldrndservices.com>
 */

#include "libssh2.h"

#include "labssh2.h"

labssh2_status_t
labssh2_initialize()
{
    libssh2_init(0);
    return LABSSH2_STATUS_OK;
}

labssh2_status_t
labssh2_shutdown()
{
    libssh2_exit();
    return LABSSH2_STATUS_OK;
}

const char*
labssh2_version()
{
    return VERSION;
}

unsigned int
labssh2_version_major()
{
    return VERSION_MAJOR;
}

unsigned int
labssh2_version_minor()
{
    return VERSION_MINOR;
}

unsigned int
labssh2_version_patch()
{
    return VERSION_PATCH;
}

labssh2_status_t
labssh2_internal_version_len(
    size_t* len
) {
    const char* version = libssh2_version(0);
    if (version == NULL) {
        return LABSSH2_STATUS_ERROR_VERSION_TOO_OLD;
    }
    *len = strlen(version);
    return LABSSH2_STATUS_OK;
}

labssh2_status_t
labssh2_internal_version(
    uint8_t* buffer
) {
    const char* version = libssh2_version(0);
    if (version == NULL) {
        return LABSSH2_STATUS_ERROR_VERSION_TOO_OLD;
    }
    memcpy(buffer, version, strlen(version));
    return LABSSH2_STATUS_OK;
}

