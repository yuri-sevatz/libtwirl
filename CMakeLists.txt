cmake_minimum_required(VERSION 2.8.8)

# project details
# ---------------
project(twirl)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

find_package(Qt5 COMPONENTS Core Network WebKit WebKitWidgets REQUIRED)

set(${PROJECT_NAME}_pub_headers
    app/bootstrap.hpp
    model/login.hpp
    model/session.hpp
    util/delay.hpp
    web/domloader.hpp
    web/pageloader.hpp
    web/requestloader.hpp
)

set(${PROJECT_NAME}_pub_sources

)

set(${PROJECT_NAME}_pri_headers
    model/logindata.hpp
    model/sessiondata.hpp
)

set(${PROJECT_NAME}_pri_sources
    app/bootstrap.cpp
    model/login.cpp
    model/session.cpp
    util/delay.cpp
    web/domloader.cpp
    web/pageloader.cpp
    web/requestloader.cpp
)

set(${PROJECT_NAME}_headers
    ${${PROJECT_NAME}_pub_headers}
    ${${PROJECT_NAME}_pri_headers}
)

set(${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_pub_sources}
    ${${PROJECT_NAME}_pri_sources}
)

QT5_WRAP_CPP(${PROJECT_NAME}_headers_moc ${${PROJECT_NAME}_headers})

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_headers_moc} ${${PROJECT_NAME}_sources})

qt5_use_modules(${PROJECT_NAME} Core Network WebKit WebKitWidgets)

install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)

foreach(header ${${PROJECT_NAME}_pub_headers})
	string(REGEX MATCH "(.*)[/\\]" dir ${header})
	install(FILES ${header} DESTINATION include/lib${PROJECT_NAME}/${dir})
endforeach(header ${${PROJECT_NAME}_pub_headers})
