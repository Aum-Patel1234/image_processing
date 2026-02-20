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
        st.image(cv2.cvtColor(img, cv2.COLOR_BGR2RGB), use_container_width=True)

    with col2:
        st.header("Processed Image")

        option = st.selectbox(
            "Select Filter",
            ("Sobel X", "Sobel Y", "Sobel", "Mean Blur", "Gaussian Blur"),
        )

        if option == "Gaussian Blur":
            ksize = st.slider("Kernel Size", 3, 21, 5, step=2)
            sigma = st.slider("Sigma", 0.1, 5.0, 1.0)
            processed_img = image_processing.gaussian_blur(img, ksize, sigma)

        elif option == "Sobel X":
            processed_img = image_processing.sobel_x_gray(img)

        elif option == "Sobel Y":
            processed_img = image_processing.sobel_y_gray(img)

        elif option == "Mean Blur":
            processed_img = image_processing.mean_blur(img)

        else:  # Sobel
            processed_img = image_processing.sobel_gray(img)

        st.image(processed_img, caption=option, use_container_width=True)
