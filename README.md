      ,```     O-                    <<**`                               ,,``     ``                       
    -X*OO@     <.                    ``,O,                     =O@<    -X**O@  --OOO@<< *O@OOO  *OO@OO     
    O, ``O  ,<<<`  <<<=<<<<`-<`<<<      O,     <=<<             ==X    O,  `O `OO<  O<<   O``      O`      
    O<`     ,<<O,  oo@o@X**o-OO***O`    O,    **<==O.           O O,,  O<``   <OO   ,,,   O``      O`      
    ,%@OO<     X,  --* X<<<% O<   =<    O,   <@<---O<          <= <==  ,%@@O< =%%         O``      O`      
    ,  ,,O,    X,  --* *,<<* O,   <*    O,   <O=====-          *OOOOO  ,   ,O,<OO         O``      O`      
   ,@.   O,    X,  --* *,<<* O%``,O<    O,   ,@,   -,        ..O   **<,@.   O,.@@<  <<<   O``      O`      
   ,@O*OO=  XOO@OO<XX@<**,,@-O=OOOo  **O@OO-- <OOOOX,        OO@= <OO@-@O**O=  --OOO*,, *O@OOO  *OO@OO     
    ,`,                      O,                 ,``                    ,`,,       ,`                       
                            <@=<<                                                                          
                            ,<<<<                                                                          
                  ,``                                                                                      
                -OOOO@-                                            OO                                      
               ,@< ``O<  <<=<  ,,<,o<``   <==<   <<< <=,, `<=<<   ,OO,,`    ,o-    <<  <=,                 
               oO    `  ***<=O.,,XOo*%%  **<<=O. <<@%%=<< <=<**o <X@@XX=   **<%OO, <@%%%=<                 
               == `,,,,<@<<--O<  %o `OO <@<---O<   O<     `<===O   OO    <<O   **=  O<<                    
               oO ,%%O%<O=====-  %<  OO <O=====-   O      O=<<<O   OO    <<*   oo%  O                      
               ,@<   =<,@,,  -,  %<  OO ,@,   -,   O     ,O  ==O   @@` ,,--@, `OO<  O                      
                <OO**O< <OOOOX,--@O`=@@= <OOOOX,-OO@OO<   %OO==@=  ==OOO<  <XOOoo -O@OOO<                  
                  ,,,      ,`              ,,`             `          `      `                                                                                                                                        

A simple ASCII-Art Generator.

To use, run AsciiGenerator example/input.bmp example/definitions.txt [grid size width] [grid size height]

The definitions file maps characters (including unicode characters) to darkness values. The format of the file is [character]:[value], where the entries are separated by newlines and the last entry ends with a semicolon. Note - ':' and ';' are reserved characters; trying to map a colon or semi-colon will cause the program to fail.

The grid size defines scale - for example, a grid size of 2, 3 will average a block of 6 pixels two pixels wide and three pixels tall. This argument is optional.
