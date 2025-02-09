
# Copyright Aleksey Gurtovoy 2001-2006
#
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt)
#
# See http://www.boost.org/libs/mpl for documentation.

# $Id: preprocess_list.py,v 1.1 2020/09/08 21:22:10 kurt Exp $
# $Date: 2020/09/08 21:22:10 $
# $Revision: 1.1 $

import preprocess
import os.path

preprocess.main(
      [ "plain" ]
    , "list"
    , os.path.join( "boost", "mpl", "list", "aux_", "preprocessed" )
    )
