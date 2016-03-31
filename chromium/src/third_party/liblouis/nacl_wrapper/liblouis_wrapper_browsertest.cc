// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/base_paths.h"
#include "base/files/file_path.h"
#include "base/path_service.h"
#include "chrome/browser/extensions/extension_apitest.h"

class LibLouisWrapperTest : public ExtensionApiTest {
};

IN_PROC_BROWSER_TEST_F(LibLouisWrapperTest, LibLouisLoad) {
  ASSERT_TRUE(PathService::Get(base::DIR_EXE, &test_data_dir_));
  test_data_dir_ = test_data_dir_.AppendASCII("chromevox_test_data");
  LOG(ERROR) << "Test data dir: " << test_data_dir_.MaybeAsASCII();
  ASSERT_TRUE(RunExtensionTest("braille")) << message_;
}
