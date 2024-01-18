// Copyright 2024 zhangwfjh
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "psi/psi/operator/kmprt17_mp_psi.h"

#include <memory>

#include "psi/psi/operator/factory.h"

namespace psi::psi {

namespace {

std::unique_ptr<PsiBaseOperator> CreateOperator(
    const MemoryPsiConfig& config,
    const std::shared_ptr<yacl::link::Context>& lctx) {
  return std::make_unique<KmprtMpPsiOperator>(
      KmprtMpPsiOperator::Options({lctx, config.receiver_rank()}));
}

REGISTER_OPERATOR(KMPRT_PSI_NPC, CreateOperator);

}  // namespace

}  // namespace psi::psi