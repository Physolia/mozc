// Copyright 2010-2021, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Helper class for singleton window
//
// usage:
// int RunWindow() {
//   ..
//   SingletonWindowHelper helper(unique_name);
//   if (helper.FindPreviousWindow()) {
//     ActivatePreviousWindow();
//     return -1;
//   }
//   app.show();
//   ..
// }

#ifndef MOZC_GUI_BASE_SINGLETON_WINDOW_HELPER_H_
#define MOZC_GUI_BASE_SINGLETON_WINDOW_HELPER_H_

#include <memory>

#include "base/process_mutex.h"
#include "absl/strings/string_view.h"

namespace mozc {
namespace gui {

class SingletonWindowHelper final {
 public:
  // name should be unique for the window.
  explicit SingletonWindowHelper(absl::string_view name);

  SingletonWindowHelper(const SingletonWindowHelper&) = delete;
  SingletonWindowHelper& operator=(const SingletonWindowHelper&) = delete;

  // Find previous window using 'name'.
  bool FindPreviousWindow();

  // Activate window.
  bool ActivatePreviousWindow();

 private:
  std::unique_ptr<ProcessMutex> mutex_;
};

}  // namespace gui
}  // namespace mozc

#endif  // MOZC_GUI_BASE_SINGLETON_WINDOW_HELPER_H_
