# minishell

https://www.aosabook.org/en/bash.html  
https://stackoverflow.com/questions/5491775/how-to-write-a-shell-lexer-by-hand  
https://rosettacode.org/wiki/Compiler/lexical_analyzer
https://rosettacode.org/wiki/Compiler/syntax_analyzer
https://rosettacode.org/wiki/Compiler/AST_interpreter
https://codereview.stackexchange.com/questions/125820/tokenizing-a-shell-command
http://www.cs.man.ac.uk/~pjj/farrell/compmain.html
http://www.cs.man.ac.uk/~pjj/farrell/comp3.html
https://people.inf.ethz.ch/wirth/CompilerConstruction/CompilerConstruction1.pdf
https://brennan.io/2015/01/16/write-a-shell-in-c/   
https://fr.wikipedia.org/wiki/Analyse_lexicale   
https://en.wikipedia.org/wiki/Parsing  
https://en.wikipedia.org/wiki/Lexical_analysis   
https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

https://mtodorovic.developpez.com/linux/programmation-avancee/?page=page_3  

https://stackoverflow.com/questions/8082932/connecting-n-commands-with-pipes-in-a-shell   
https://stackoverflow.com/questions/34625123/how-to-correctly-wait-for-execve-to-finish   
http://www.zeitoun.net/articles/communication-par-tuyau/start     
http://www.makelinux.net/alp/    

https://cs61.seas.harvard.edu/site/2018/Shell2/   
http://www.cs.uleth.ca/~holzmann/C/system/pipeforkexec.html    
https://stackoverflow.com/questions/47767995/exec-and-pipe-between-child-process-in-c    

https://brandonwamboldt.ca/how-bash-redirection-works-under-the-hood-1512/   
https://brandonwamboldt.ca/how-linux-pipes-work-under-the-hood-1518/    
https://catonmat.net/bash-one-liners-explained-part-three   
https://abs.traduc.org/abs-5.1-fr/ch19.html  
https://pubs.opengroup.org/onlinepubs/009604499/utilities/xcu_chap02.html#tag_02_07   

http://www.idc-online.com/technical_references/pdfs/information_technology/How_Linux_pipes_work_under_the_hood.pdf   

https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10   

https://stackoverflow.com/questions/61953361/uncleanly-exiting-from-c-child-process-without-valgrind-complaining   
https://valgrind.org/docs/manual/ms-manual.html#ms-manual.forkingprograms   
https://shapeshed.com/unix-exit-codes/  
https://tldp.org/LDP/abs/html/exitcodes.html
https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_08_02   

https://stackoverflow.com/questions/9084099/re-opening-stdout-and-stdin-file-descriptors-after-closing-them

- [x] Afficher un prompt en l’attente d’une nouvelle commande
- [x] Chercher et lancer le bon executable (basé sur une variable d’environnement PATH ou en utilisant un path absolu), comme dans bash
- [x] Vous devez implémenter les builtins suivants :
  - [x] echo et l’option ’-n’
  - [x] cd uniquement avec un chemin absolu ou relatif
  - [x] pwd sans aucune option
  - [x] export sans aucune option
  - [x] unset sans aucune option
  - [x] env sans aucune option ni argument
  - [x] exit sans aucune option 
- [x] ; dans la ligne de commande doit séparer les commandes
- [x] ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
- [ ] Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des aggrégations de fd

- [x] Pipes | doivent marcher comme dans bash.
- [x] Les variables d’environnement ($suivi de caractères) doivent marcher comme dans bash.
- [x] $? doit marcher comme dans bash
- [ ] ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
