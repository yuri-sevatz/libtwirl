cmake_minimum_required(VERSION 2.8)

# project details
# ---------------
project(twirl)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(QT_USE_NETWORK TRUE)
set(QT_USE_QTWEBKIT TRUE)
find_package(Qt4 REQUIRED)

set(${PROJECT_NAME}_pub_headers
    app/bootstrap.hpp
    model/login.hpp
    model/session.hpp
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

QT4_WRAP_CPP(${PROJECT_NAME}_headers_moc ${${PROJECT_NAME}_headers})

# Pre-linkage Qt
# ---------------
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

# Linked Libraries
# ---------------
message("QT_LIBRARIES")
message(${QT_LIBRARIES})

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_headers_moc} ${${PROJECT_NAME}_sources})

target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)