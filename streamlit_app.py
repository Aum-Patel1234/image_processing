import cv2
import numpy as np
import streamlit as st
import sys, os

sys.path.append(os.path.abspath("core/build"))
import image_processing

st.title("Sobel Edge Detection - Grayscale")

img_path = "img.PNG"
img = cv2.imread(img_path, cv2.IMREAD_COLOR)

if img is None:
    st.error("Failed to load image")
else:
    col1, col2 = st.columns(2)

    with col1:
        st.header("Original Image")
        st.image(cv2.cvtColor(img, cv2.COLOR_BGR2RGB), width=400)

    with col2:
        st.header("Processed Image")
        option = st.selectbox("Select Sobel Filter", ("Sobel X", "Sobel Y"))

        if option == "Sobel X":
            sobel_img = image_processing.sobel_x_gray(img)
        else:
            sobel_img = image_processing.sobel_y_gray(img)

        st.image(sobel_img, caption=f"{option} (Grayscale)", width=400)
