/* 
 * File:   fileOwnCloud.cpp
 * Author: riema
 * 
 * Created on 11. září 2012, 19:39
 */

#include "fileOwnCloud.h"
#include "../commons.h"

FileOwnCloud::FileOwnCloud() {
    system("dolphin webdav://riema@127.0.0.1:80/owncloud/files/webdav.php");
}

FileOwnCloud::~FileOwnCloud() {
}

