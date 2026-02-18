# Image Processing Lab — Streamlit App

An interactive **Computer Vision playground** built with Streamlit that demonstrates classical image processing and real-time vision techniques.
Users can upload images or use a live camera to apply filters, edge detection, color transforms, and geometric operations.

---

# Project Goals

* Have Fun
* Learn and visualize core image processing operations
* Build intuition for gradients, edges, and filtering
<!-- * Provide interactive sliders for parameters -->
* Support both uploaded images and live camera

---

# ✅ Core Features Checklist

## 🖼️ Image Input

* [ ] Upload image
* [ ] Drag & drop support
* [ ] Webcam capture
* [ ] Reset to original

---

# 🎨 Basic Processing

* [ ] Grayscale
* [ ] RGB channel view
* [ ] Image negative
* [ ] Brightness slider
* [ ] Contrast slider
* [ ] Gamma correction

---

# 🌫️ Filtering & Blur

* [ ] Gaussian blur
* [ ] Median blur
* [ ] Bilateral filter
* [ ] Sharpen filter
* [ ] Custom kernel convolution

---

# 🔍 Edge Detection

* [ ] Sobel X
* [ ] Sobel Y
* [ ] Gradient magnitude
* [ ] Laplacian
* [ ] Canny edge detector
* [ ] Edge orientation visualization

---

# 📊 Histogram & Tone

* [ ] Histogram plot
* [ ] Histogram equalization
* [ ] Adaptive equalization (CLAHE)
* [ ] Threshold (binary)
* [ ] Adaptive threshold

---

# 🎨 Color Space Operations

* [ ] RGB ↔ HSV
* [ ] Saturation control
* [ ] Hue shift
* [ ] Sepia filter
* [ ] Color quantization (cartoon)

---

# 📐 Geometric Transformations

* [ ] Resize
* [ ] Rotate
* [ ] Flip H/V
* [ ] Crop
* [ ] Translate
* [ ] Affine transform
* [ ] Perspective warp

---

# 🔬 Morphological Ops

* [ ] Erosion
* [ ] Dilation
* [ ] Opening
* [ ] Closing
* [ ] Morphological gradient

---

# 🧠 Advanced Vision

* [ ] Contour detection
* [ ] Bounding boxes
* [ ] Harris corner detection
* [ ] Hough line detection
* [ ] Image segmentation (threshold / GrabCut)
* [ ] Background removal

---

# 📷 Live Camera Mode

* [ ] Webcam stream
* [ ] Live Sobel edges
* [ ] Live Canny
* [ ] Live blur
* [ ] Live grayscale
* [ ] Live color tracking
* [ ] Live sketch mode

---

# 🤖 Optional ML Extensions

* [ ] Image classification (MobileNet)
* [ ] Object detection (YOLO)
* [ ] Style transfer
* [ ] Super resolution
* [ ] Face detection
* [ ] Pose estimation

---

# 🎛️ UI Enhancements

* [ ] Sidebar controls
* [ ] Parameter sliders
* [ ] Before/After comparison
* [ ] Histogram panel
* [ ] Download result
* [ ] Kernel visualizer
* [ ] Processing time display

---

# 🧪 Educational Visualizations (Unique)

* [ ] Gradient magnitude heatmap
* [ ] Gradient direction map
* [ ] Sobel kernel explanation
* [ ] Frequency domain (FFT)
* [ ] Noise simulator + denoise
* [ ] Edge overlay on original

---

# 🚀 Implementation Steps

## Phase 1 — Basic App

* [ ] Setup Streamlit app
* [ ] Upload image
* [ ] Display original
* [ ] Grayscale + blur + resize

## Phase 2 — Filters & Edges

* [ ] Convolution module
* [ ] Sobel / Laplacian / Canny
* [ ] Parameter sliders

## Phase 3 — Color & Histogram

* [ ] HSV conversion
* [ ] Histogram + equalization
* [ ] Tone controls

## Phase 4 — Geometry

* [ ] Rotation / flip / crop
* [ ] Perspective transform

## Phase 5 — Advanced CV

* [ ] Contours
* [ ] Morphology
* [ ] Segmentation

## Phase 6 — Live Camera

* [ ] Webcam stream
* [ ] Real-time filters

## Phase 7 — Polish

* [ ] UI improvements
* [ ] Download option
* [ ] Performance optimize

---

# 📦 requirements.txt

```
streamlit
opencv-python
numpy
pillow
matplotlib
streamlit-webrtc
```

---

# ⭐ Future Ideas

* Kernel editor
* Compare filters side-by-side
* Upload video processing
* Batch image processing
* API mode (FastAPI)
* Deploy on Streamlit Cloud

---

# 📜 License

MIT