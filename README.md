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

- [x] Afficher un prompt en l’attente d’une nouvelle commande
- [x] Chercher et lancer le bon executable (basé sur une variable d’environnement PATH ou en utilisant un path absolu), comme dans bash
- [ ] Vous devez implémenter les builtins suivants :
  - [ ] echo et l’option ’-n’
  - [ ] cd uniquement avec un chemin absolu ou relatif
  - [ ] pwd sans aucune option
  - [ ] export sans aucune option
  - [ ] unset sans aucune option
  - [ ] env sans aucune option ni argument
  - [ ] exit sans aucune option 
- [ ] ; dans la ligne de commande doit séparer les commandes
- [ ] ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
- [ ] Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des aggrégations de fd

- [ ] Pipes | doivent marcher comme dans bash.
- [ ] Les variables d’environnement ($suivi de caractères) doivent marcher comme dansbash.
- [ ] $? doit marcher comme dans bash
- [ ] ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
