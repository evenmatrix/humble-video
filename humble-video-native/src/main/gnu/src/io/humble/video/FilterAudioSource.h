/*******************************************************************************
 * Copyright (c) 2014, Andrew "Art" Clarke.  All rights reserved.
 *   
 * This file is part of Humble-Video.
 *
 * Humble-Video is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Humble-Video is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Humble-Video.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
/*
 * FilterAudioSource.h
 *
 *  Created on: Aug 5, 2013
 *      Author: aclarke
 */

#ifndef FILTERAUDIOSOURCE_H_
#define FILTERAUDIOSOURCE_H_

#include <io/humble/video/FilterSource.h>
#include <io/humble/video/MediaAudio.h>

namespace io {
namespace humble {
namespace video {

/**
 * A source of MediaAudio objects for a FilterGraph.
 */
class VS_API_HUMBLEVIDEO FilterAudioSource : public io::humble::video::FilterSource
{
public:

  /**
   * Adds audio to this source. NOTE: If you had audio to a FilterSource
   * be careful with re-using or rewriting the underlying data. Filters will
   * try hard to avoid copying data, so if you change the data out from under
   * them unexpected results can occur.
   * @param audio the audio to add. Must be non-null and complete.
   * @throws InvalidArgument if audio is null or audio is not complete.
   */
  void
  addAudio(MediaAudio* audio);

#ifndef SWIG
  static FilterAudioSource*
  make(FilterGraph* graph, AVFilterContext* ctx);
#endif // ! SWIG
protected:
//  virtual void* getCtx() { return Filter::getCtx(); }
  FilterAudioSource(FilterGraph* graph, AVFilterContext* ctx);
  virtual
  ~FilterAudioSource();
};

} /* namespace video */
} /* namespace humble */
} /* namespace io */
#endif /* FILTERAUDIOSOURCE_H_ */
