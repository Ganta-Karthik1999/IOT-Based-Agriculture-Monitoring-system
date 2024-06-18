import cv2
import numpy as np

# Load the reference images
image1 = cv2.imread(r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Soil1.jpg')  # Dry soil (light brown)
image2 = cv2.imread(r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Soil2.jpg')  # Wet soil (dark brown)

# Convert reference images to HSV color space
hsv_image1 = cv2.cvtColor(image1, cv2.COLOR_BGR2HSV)
hsv_image2 = cv2.cvtColor(image2, cv2.COLOR_BGR2HSV)

# Compute the average HSV values for the reference images
mean_hsv_image1 = np.mean(hsv_image1, axis=(0, 1))
mean_hsv_image2 = np.mean(hsv_image2, axis=(0, 1))

# Function to classify new images based on the reference colors
def classify_image(image):
    hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    mean_hsv_image = np.mean(hsv_image, axis=(0, 1))
    
    # Compute the Euclidean distances to the reference HSV values
    dist1 = np.linalg.norm(mean_hsv_image - mean_hsv_image1)
    dist2 = np.linalg.norm(mean_hsv_image - mean_hsv_image2)
    
    # Determine the classification based on the minimum distance
    if dist1 < dist2 and dist1 < 50:  # Adjust threshold as needed
        return 1  # Light brown (dry soil)
    elif dist2 < dist1 and dist2 < 50:  # Adjust threshold as needed
        return 0  # Dark brown (wet soil)
    else:
        return 2  # Neither color detected

# Function to process multiple input images and display the results
def process_images(image_paths):
    for image_path in image_paths:
        image = cv2.imread(image_path)
        if image is None:
            print(f"Error: Could not load image {image_path}.")
            continue

        classification = classify_image(image)
        if classification == 1:
            label = "Dry Soil"
        elif classification == 0:
            label = "Wet Soil"
        else:
            label = "No Soil"

        cv2.putText(image, label, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
        cv2.imshow('Soil Classification', image)
        
        while True:
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        cv2.destroyAllWindows()  # Close the window for the current image

# Example usage with six specific image files
image_paths = [
    r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Test\test2_dry.jpg',
    r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Test\test1_dry.jpg',
    r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Test\test3_dry.jpg',
    r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Test\test2_wet.jpg',
    r'D:\GitHub Repository\IOT-Based-Agriculture-Monitoring-system\Resources\Test\test3_wet.jpg'
]

process_images(image_paths)