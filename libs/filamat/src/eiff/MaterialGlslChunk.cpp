/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "MaterialGlslChunk.h"

namespace filamat {

MaterialGlslChunk::MaterialGlslChunk(const std::vector<GlslEntry> &entries,
                                     LineDictionary &dictionary,
                                     ChunkType chunkType) :
    GlslChunk(chunkType, entries, dictionary) {
}

void MaterialGlslChunk::writeEntryAttributes(size_t entryIndex, Flattener& f) {
    const GlslEntry& entry = mEntries[entryIndex];
    f.writeUint8(entry.shaderModel);
    f.writeUint8(entry.variant);
    f.writeUint8(entry.stage);
}

const char* MaterialGlslChunk::getShaderText(size_t entryIndex) const {
    return mEntries[entryIndex].shader;
}

} // namespace filamat
