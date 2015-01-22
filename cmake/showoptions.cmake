# output generic information about the core and buildtype chosen
message("")
message("* FoxEmu revision       : ${rev_hash} ${rev_date} (${rev_branch} branch)")
if( UNIX )
  message("* FoxEmu buildtype        : ${CMAKE_BUILD_TYPE}")
endif()
message("")

# output information about installation-directories and locations

message("* Install core to        : ${CMAKE_INSTALL_PREFIX}")
if( UNIX )
  message("* Install libraries to   : ${LIBSDIR}")
  message("* Install configs to     : ${CONF_DIR}")
endif()
message("")

# Show infomation about the options selected during configuration

if( LOGONSERVER )
  message("* Build logonserver      : Yes")
else()
  message("* Build logonserver      : No (default)")
endif()

if( GAMENODE )
  message("* Build gamenode         : Yes (default)")
else()
  message("* Build gamenode         : No")
endif()

if ( WITHOUT_GIT )
  message("* Use GIT revision hash  : No")
  message("")
  message(" *** WITHOUT_GIT - WARNING!")
  message(" *** By choosing the WITHOUT_GIT option you have waived all rights for support,")
  message(" *** and accept that or all requests for support or assistance sent to the core")
  message(" *** developers will be rejected. This due to that we will be unable to detect")
  message(" *** what revision of the codebase you are using in a proper way.")
  message(" *** We remind you that you need to use the repository codebase and a supported")
  message(" *** version of git for the revision-hash to work, and be allowede to ask for")
  message(" *** support if needed.")
else()
  message("* Use GIT revision hash  : Yes")
endif()

message("")
