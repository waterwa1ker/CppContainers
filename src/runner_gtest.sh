 #!/bin/bash
 apt-get install -y libgtest-dev cmake
 mkdir -p $HOME/build
 cd $HOME/build
 cmake /usr/src/googletest/googletest
 make
#  cp -f lib/*.a /usr/lib/
 cd ..
 rm -rf build
 mkdir /usr/local/lib/googletest
 ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a
 ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a