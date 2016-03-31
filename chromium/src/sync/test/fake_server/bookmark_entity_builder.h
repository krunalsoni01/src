// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYNC_TEST_FAKE_SERVER_BOOKMARK_ENTITY_BUILDER_H_
#define SYNC_TEST_FAKE_SERVER_BOOKMARK_ENTITY_BUILDER_H_

#include <string>

#include "base/memory/scoped_ptr.h"
#include "sync/internal_api/public/base/model_type.h"
#include "sync/test/fake_server/fake_server_entity.h"
#include "url/gurl.h"

namespace fake_server {

// Builder for BookmarkEntity objects.
class BookmarkEntityBuilder {
 public:
  BookmarkEntityBuilder(const std::string& title,
                        const std::string& originator_cache_guid,
                        const std::string& originator_client_item_id);

  ~BookmarkEntityBuilder();

  // Sets the parent ID of the bookmark to be built. If this is not called,
  // the bookmark will be included in the bookmarks bar.
  void SetParentId(const std::string& parent_id);

  // Builds and returns a FakeServerEntity representing a bookmark. Returns null
  // if the entity could not be built.
  scoped_ptr<FakeServerEntity> BuildBookmark(const GURL& url);

  // Builds and returns a FakeServerEntity representing a bookmark folder.
  // Returns null if the entity could not be built.
  scoped_ptr<FakeServerEntity> BuildFolder();

 private:
  // Creates an EntitySpecifics and pre-populates its BookmarkSpecifics with
  // the entity's title.
  sync_pb::EntitySpecifics CreateBaseEntitySpecifics() const;

  // Builds the parts of a FakeServerEntity common to both normal bookmarks and
  // folders.
  scoped_ptr<FakeServerEntity> Build(
      const sync_pb::EntitySpecifics& entity_specifics,
      bool is_folder);

  // The bookmark entity's title. This value is also used as the entity's name.
  const std::string title_;

  // Information that associates the bookmark with its original client.
  const std::string originator_cache_guid_;
  const std::string originator_client_item_id_;

  // The ID of the parent bookmark folder.
  std::string parent_id_;
};

}  // namespace fake_server

#endif  // SYNC_TEST_FAKE_SERVER_BOOKMARK_ENTITY_BUILDER_H_
