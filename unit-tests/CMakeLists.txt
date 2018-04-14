# Copyright 2015 Atria Dynamics LLC
#
# Written by Joe Turner <joe@atriadynamics.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.#
##############################################################################

FILE(GLOB UnitTests_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*_test.cpp" )

ADD_EXECUTABLE(ut_jfc cppunit-test-main.cpp ${UnitTests_SRCS} )
TARGET_LINK_LIBRARIES(ut_jfc cppunit jfc)

ADD_TEST(ut_jfc ut_jfc)

