set(srcs "main.c")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ".")

target_add_binary_data(${COMPONENT_TARGET}
    "basic_ble_oad_dual_image_v2.bin"
    BINARY)
