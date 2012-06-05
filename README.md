      ++++++   ++                          +++                  +         ++++++     ++++++++++++++++++++  
     +X-+-XX   XX+                        +XX+                 +X+      +-X++XX+   ++XX++-XX+++XX-+++XX-+  
     XX   +X+  ++                          +X+                 +X-      +X+  +-+  +-X+    +X+  XX+   XX+   
    +XX    -+                              +X+                 XXX+     +X+   +-  +X-      -+  XX+   XX+   
     XX++  ++  +++  ++++++ ++++   ++++-+   +X+   ++++         +-+X-     +XX+   + +XX+      ++  XX+   XX+   
     +XXX+    +XX+ +XX--XX+--XX++-XX--XX+  +X+  -++-X+        -++XX+    +XXX++   +XX+          XX+   XX+   
      +XXX++   +X+  XX+ +XX+ +X+  XX+ +XX+ +X+ +-  +XX       +X+ +X+     +-XXX+  +XX           XX+   XX+   
       +-XX-+  +X+  XX   X-  +X+  X-   +X+ +X+ XX---XX       ++  +XX+      +XXX+ +XX           XX+   XX+   
         +XX+  +X+  XX   X-  +X+  X-   +X+ +X+ X+           +XXXXXXX+       +-XX +XX+          XX+   XX+   
    ++    +X-  +X+  XX   X-  +X+  X-   +X+ +X+ X-    ++     +-    +XX   -    +XX+ XX+          XX+   XX+   
    +-    +X+  +X+  XX   X-  +X+  X-   -X  +X+ -X+   ++     X+     XX+  X+    XX+ +XX+     ++  XX+   XX+   
    +X++ +-X+  -X+  XX   X-  +X+  XX+ +X+  -X+ +XX++-+     +X      +X-  -X+  +X+   +XX+  ++-+  XX+   XX+   
    +X---X-+  +-X-++XX+++XX+++X-+ XX--X+  +-X++ +XXX+     +-X++   +-XX+ -+--XX++    +-XXXX++ +-XX-++-XX-+  
                                  X-                                                   ++                  
                                  X-                                                                       
                                 +XX                                                                       
                                ++--++                                                                     
                                                                                                           
                                                                                                           
                        +++++ +                                                                            
                      +XX-++XXX                                                                            
                     +XX+   +-X                                          ++                                
                    +XX+     +X                                         +X+                                
                    +X-       +   +++++  +++++++   +++++  ++++++ +++++ +-X-++  ++++   ++++++               
                    -X+          +-++XX++-X---XX  +-++XX++-X-XX-+X+ -X ++X++++--++X-++-X-XX-               
                    XX+    ++---+-+  +X- +X-+ +X+ -+  +X- +X- +++X+ +X+ +X+  +X+  +X+ +X- ++               
                    XX+      XX++X----X- +X+  +X++X----X- +X+   ++ +-X+ +X+  X-   +XX +X+                  
                    -X+      -X++X+      +X+  +X++X+      +X+    +-++X+ +X+ +X-    XX +X+                  
                    +XX      -X++X+    +++X+  +X++X+    +++X+   +X+ +X+ +X+ +XX    XX +X+                  
                    +XX+     -X+ XX+  +-++X+  +X+ XX+  +-++X+   XX  +X+ +X+  -X+   X- +X+                  
                     +XX++  +XX+ +XX++X+ +X-  +X+ +XX++X+ +X+   XX++-X+++X-+++X-  +X+ +X+                  
                      ++XXXXX-+   +XXX+ ++X-++-X-+ +XXX+ +-X-+  +XX++X-++-X-+ +X---+ +-X-+                 
                          +                                                     ++                         

A simple ASCII-Art Generator.

To use, run AsciiGenerator example/input.bmp example/definitions.txt [grid size]

The definitions file maps characters (including unicode characters) to darkness values. Note - ':' is a reserved character; trying to map a colon will cause the program to fail.

The grid size defines scale - for example, a grid size of 2 will average a block of 4 pixels. This argument is optional.
