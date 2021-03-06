/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_map>

// template <class Key, class T, class Hash, class Pred, class Alloc>
// bool
// operator==(const unordered_multimap<Key, T, Hash, Pred, Alloc>& x,
//            const unordered_multimap<Key, T, Hash, Pred, Alloc>& y);
//
// template <class Key, class T, class Hash, class Pred, class Alloc>
// bool
// operator!=(const unordered_multimap<Key, T, Hash, Pred, Alloc>& x,
//            const unordered_multimap<Key, T, Hash, Pred, Alloc>& y);

#include <unordered_map>
#include <string>
#include <cassert>
#include "libcxx_tc_common.h"


int tc_libcxx_containers_unord_multimap_eq(void)
{
    {
        typedef std::unordered_multimap<int, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(10, "ten"),
            P(20, "twenty"),
            P(20, "twenty 2"),
            P(30, "thirty"),
            P(40, "forty"),
            P(50, "fifty"),
            P(50, "fifty 2"),
            P(50, "fifty 3"),
            P(60, "sixty"),
            P(70, "seventy"),
            P(80, "eighty"),
        };
        const C c1(std::begin(a), std::end(a));
        const C c2;
        TC_ASSERT_EXPR(!(c1 == c2));
        TC_ASSERT_EXPR( (c1 != c2));
    }
    {
        typedef std::unordered_multimap<int, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(10, "ten"),
            P(20, "twenty"),
            P(20, "twenty 2"),
            P(30, "thirty"),
            P(40, "forty"),
            P(50, "fifty"),
            P(50, "fifty 2"),
            P(50, "fifty 3"),
            P(60, "sixty"),
            P(70, "seventy"),
            P(80, "eighty"),
        };
        const C c1(std::begin(a), std::end(a));
        const C c2 = c1;
        TC_ASSERT_EXPR( (c1 == c2));
        TC_ASSERT_EXPR(!(c1 != c2));
    }
    {
        typedef std::unordered_multimap<int, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(10, "ten"),
            P(20, "twenty"),
            P(20, "twenty 2"),
            P(30, "thirty"),
            P(40, "forty"),
            P(50, "fifty"),
            P(50, "fifty 2"),
            P(50, "fifty 3"),
            P(60, "sixty"),
            P(70, "seventy"),
            P(80, "eighty"),
        };
        C c1(std::begin(a), std::end(a));
        C c2 = c1;
        c2.rehash(30);
        TC_ASSERT_EXPR( (c1 == c2));
        TC_ASSERT_EXPR(!(c1 != c2));
        c2.insert(P(90, "ninety"));
        TC_ASSERT_EXPR(!(c1 == c2));
        TC_ASSERT_EXPR( (c1 != c2));
        c1.insert(P(90, "ninety"));
        TC_ASSERT_EXPR( (c1 == c2));
        TC_ASSERT_EXPR(!(c1 != c2));
    }
    TC_SUCCESS_RESULT();
    return 0;
}
