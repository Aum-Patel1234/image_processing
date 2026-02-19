import cv2, numpy as np
import streamlit as st
import sys, os

sys.path.append(os.path.abspath("core/build"))
import image_processing

# uploaded_file = st.file_uploader("Upload image", type=["png", "jpg", "jpeg"])
# if uploaded_file:
#     file_bytes = np.asarray(bytearray(uploaded_file.read()), dtype=np.uint8)
#     img = cv2.imdecode(file_bytes, cv2.IMREAD_COLOR)
#
#     st.image(cv2.cvtColor(img, cv2.COLOR_BGR2RGB), caption="Original")
#
#     sobel_x_img = image_processing.sobel_x(img)
#     sobel_y_img = image_processing.sobel_y(img)
#
#     st.image(sobel_x_img, caption="Sobel X")
#     st.image(sobel_y_img, caption="Sobel Y")


st.title("Sobel X Edge Detection - Grayscale")

# Read the image
img_path = "aum_img.jpeg"
img = cv2.imread(img_path, cv2.IMREAD_COLOR)

if img is None:
    st.error("Failed to load image")
else:
    st.image(cv2.cvtColor(img, cv2.COLOR_BGR2RGB), caption="Original")

    # Convert to grayscale for Sobel
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Apply Sobel X on grayscale (make sure C++ accepts CV_8UC1)
    sobel_x_img = image_processing.sobel_x(gray)

    # If C++ returns CV_32F, normalize to 0-255
    sobel_x_norm = cv2.normalize(sobel_x_img, None, 0, 255, cv2.NORM_MINMAX)
    sobel_x_norm = sobel_x_norm.astype(np.uint8)

    st.image(sobel_x_norm, caption="Sobel X (Grayscale)")
