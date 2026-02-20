# Grayscale Images in OpenCV

## 1. Conversion from BGR to Grayscale

In OpenCV, you can convert a color image to grayscale using:

```python
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
```

- Original image (img) has 3 channels: B, G, R.
- Grayscale image (gray) has 1 channel.
- Each pixel in the grayscale image is computed as a weighted sum of B, G, R:

https://en.wikipedia.org/wiki/Grayscale
```text
Gray = 0.299*R + 0.587*G + 0.11*B
```

## 2. What the single channel stores

- **Type:** `CV_8UC1` → 8-bit unsigned integer, 1 channel  
- **Value range:** 0–255  
  - 0 → black  
  - 255 → white  
  - Values in between → shades of gray  
- **Important:** It does **not** store R, G, or B separately. The single value encodes **brightness/luminance**

---

## 3. How grayscale images are displayed

- Display libraries (OpenCV, Matplotlib, etc.) interpret the single channel as **intensity**  
- When shown on a color screen, the single-channel value is **replicated across R, G, B channels**, e.g.:

```text
gray_value = 124
displayed_pixel = (124, 124, 124)  # R, G, B