
##########################################################
## Makefile para usar el programa Git con el lpcxpresso ##
##########################################################

REPONAME = TP1_SSE

######################################################################################
#
# CONFIGURACIONES INICIALES:
#
# La primera vez que se utiliza el Git, es conveniente configurar los campos
# USERNAME y EMAIL, que después se muestran a lo largo del programa. El comando
#
# 	make config_git
#
# los configura como se muestra a continuación.

USERNAME = Lautaro Estienne
EMAIL = lautaro.est@gmail.com

config_git:
	@git config --global user.name "$(USERNAME)"
	@git config --global user.email "$(EMAIL)"
	@git config --list

######################################################################################
#
# CLONAR UN REPOSITORIO:
#
# Para hacer un proyecto desde cero hay que crearlo en github. Una vez hecho eso,
# se "clona" a la computadora de cada miembro del grupo, es decir que cada miembro
# del grupo va a tener una "copia" del proyecto en su computadora, sincronizada con
# la copia que se encuentra en el github. Para clonar el repositorio creado en github
# se debe tener el URL de dicho repositorio (hay una opción en la pantalla de inicio
# del repositorio de github que dice "Clone or download" de donde se puede obtener
# dicho URL.) Con ese URL, se ejecuta el comando
#
#	make clone_repository CLONE_URL = https://www.github.com/blablabla
#
# y se tiene en el lugar de trabajo el nuevo repositorio.
#

CLONE_URL ?= no_url

clone_repository:
ifeq ($(CLONE_URL),no_url)
	@echo 'No se especificó el URL del repositorio a clonar.'
else
	mkdir $(REPONAME)
	git clone $(CLONE_URL) ./$(REPONAME)
endif

######################################################################################
#
# STATUS:
#
# Una función muy útil para seguir la edición de los archivos es "status".
#

status_git:
	cd ./$(REPONAME) && git status

######################################################################################
#
# ACTUALIZAR:
#
# Las instrucciones que siguen sirve para que los archivos que se modificaron en la compu
# ahora se modifiquen en el github.
# Una vez que se editaron los archivos desde el lpcxpresso, tenemos que guardar esas
# modificaciones en el repositorio de github. Para eso, primero tenemos traemos del github
# las modificaciones que otros miembros del grupo hicieron en el repositorio. Escribimos:
#
# 	make pull_github 

BRANCH_PULL ?= master
BRANCH_PUSH ?= master

pull_github:
	cd ./$(REPONAME) && git pull origin $(BRANCH_PULL)

# Si todo salió bien, actualizamos nuestra carpeta localmente (es decir, sin subirla al github)
# con los comandos "git add -A" y "git commit -m blabla". Finalmente, se envía al github
# con el comando "git push"

MENSAJE ?= "?????"

commit_local:
	cd ./$(REPONAME) && git add -A && git commit -m $(MENSAJE)

push_github:
	cd ./$(REPONAME) && git push origin $(BRANCH_PUSH)

######################################################################################
#
# CREAR RAMAS:
#
# Para crear una nueva rama y trabajar sobre ella, se usa la siguiente intrucción:
#

BRANCH_NAME ?= no_name

nueva_rama:
ifeq ($(BRANCH_NAME),no_name)
	@echo 'Especificar nombre de la rama'
else
	cd ./$(REPONAME) && git branch $(BRANCH_NAME) && git checkout $(BRANCH_NAME)
endif

NEW_BRANCH ?= no_name

cambiar_rama:
ifeq ($(NEW_BRANCH),no_name)
	@echo 'Especificar nombre de la rama'
else
	cd ./$(REPONAME) && git checkout $(NEW_BRANCH)
endif

ver_ramas:
	cd ./$(REPONAME) && git branch -a

init_lpcxpresso:
	SWT_GTK3=0 /usr/local/lpcxpresso_8.2.0_647/lpcxpresso/lpcxpresso &
