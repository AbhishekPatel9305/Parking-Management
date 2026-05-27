# 🚗 Advanced 3D Parking Management System

A cutting-edge web-based parking management system featuring realistic 3D graphics, smooth animations, and intelligent vehicle tracking. Built with Three.js, GSAP, and a robust C++ backend.

## ✨ Features

### 🎮 3D Visualization
- **Realistic 3D Parking Lot**: Detailed 3D environment with 20 parking slots
- **Multiple Vehicle Types**: Cars, Motorcycles, Trucks, SUVs, and Vans
- **Dynamic Lighting**: Point lights for each slot, directional lighting, and atmospheric effects
- **Interactive Camera**: Orbit controls with smooth camera movements
- **Real-time Updates**: Live 3D visualization of parking status

### 🎨 Advanced Animations
- **GSAP-Powered Animations**: Smooth vehicle parking and leaving animations
- **Realistic Vehicle Movement**: Different animation patterns for each vehicle type
- **Particle Effects**: Dynamic background particles and visual feedback
- **Smooth Transitions**: Elegant UI transitions and state changes

### 🚀 Modern UI/UX
- **Glassmorphism Design**: Modern glass-like interface elements
- **Responsive Layout**: Works perfectly on desktop, tablet, and mobile
- **Real-time Statistics**: Live occupancy rates and slot availability
- **Activity Logging**: Complete history of all parking activities
- **Smart Notifications**: Animated success/error messages

### 🔧 Backend Integration
- **C++ Core Engine**: High-performance parking slot management
- **Node.js API**: RESTful API for web interface communication
- **Data Persistence**: Automatic saving and loading of parking data
- **Fee Calculation**: Dynamic pricing based on vehicle type and duration

## 🛠️ Technology Stack

### Frontend
- **Three.js**: 3D graphics and WebGL rendering
- **GSAP**: Advanced animations and transitions
- **HTML5/CSS3**: Modern web standards
- **JavaScript ES6+**: Modern JavaScript features

### Backend
- **C++**: Core parking management logic
- **Node.js**: Web API server
- **Express.js**: RESTful API framework
- **JSON**: Data interchange format

## 🚀 Quick Start

### Prerequisites
- Node.js (v14 or higher)
- C++ compiler (GCC, Clang, or MSVC)
- Modern web browser with WebGL support

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/advanced-parking-management.git
   cd advanced-parking-management
   ```

2. **Install Node.js dependencies**
   ```bash
   npm install
   ```

3. **Compile C++ backend**
   ```bash
   # Windows
   g++ -o parking_backend.exe parking_backend.cpp
   
   # Linux/Mac
   g++ -o parking_backend parking_backend.cpp
   ```

4. **Start the server**
   ```bash
   npm start
   ```

5. **Open in browser**
   ```
   http://localhost:3000
   ```

## 📖 Usage

### Parking a Vehicle
1. Enter license plate (e.g., "ABC123")
2. Select vehicle type (Car, Motorcycle, Truck, SUV, Van)
3. Click "Park Vehicle"
4. Watch the 3D animation as the vehicle parks

### Releasing a Vehicle
1. Enter the license plate
2. Click "Release Vehicle"
3. View the calculated fee and duration
4. Watch the vehicle leave in 3D

### Finding a Vehicle
1. Enter the license plate
2. Click "Find Vehicle"
3. View detailed information including current fee

### 3D Controls
- **Mouse Drag**: Rotate camera around the parking lot
- **Mouse Wheel**: Zoom in/out
- **Reset Camera**: Return to default view
- **Wireframe Toggle**: Switch between solid and wireframe view
- **Lights Toggle**: Enable/disable lighting effects

## 🎯 API Endpoints

### GET /api/parking/status
Get current parking lot status
```json
{
  "success": true,
  "data": {
    "totalSlots": 20,
    "availableSlots": 15,
    "occupiedSlots": 5,
    "occupancyRate": 25,
    "slots": [...]
  }
}
```

### POST /api/parking/park
Park a vehicle
```json
{
  "licensePlate": "ABC123",
  "vehicleType": "Car"
}
```

### POST /api/parking/release
Release a vehicle
```json
{
  "licensePlate": "ABC123"
}
```

### GET /api/parking/search/:licensePlate
Find a specific vehicle

### POST /api/parking/clear
Clear all vehicles from the parking lot

## 🎨 Customization

### Adding New Vehicle Types
1. Update the vehicle type options in `index.html`
2. Add new vehicle model in `threejs-parking.js`
3. Update fee rates in both `parking_backend.cpp` and `server.js`

### Modifying 3D Environment
- Edit `createParkingLot()` in `threejs-parking.js`
- Adjust lighting in `createLights()`
- Modify vehicle models in respective `create*Model()` functions

### Styling Changes
- Update CSS in `index.html` `<style>` section
- Modify color schemes and animations
- Add new UI components as needed

## 🚀 Deployment

### Vercel Deployment
1. Push code to GitHub repository
2. Connect repository to Vercel
3. Set build command: `npm run build`
4. Set output directory: `.`
5. Deploy!

### Local Production
1. Compile C++ backend
2. Install production dependencies: `npm install --production`
3. Start server: `npm start`
4. Access via `http://localhost:3000`

## 🔧 Configuration

### Parking Lot Settings
- **Total Slots**: Modify `totalSlots` in `parking_backend.cpp`
- **Fee Rates**: Update `feeRates` map in C++ backend
- **3D Layout**: Adjust slot positions in `createParkingSlots()`

### Animation Settings
- **Vehicle Speed**: Modify duration in `animateVehicleParking()`
- **Camera Movement**: Adjust in `resetCamera()` and orbit controls
- **UI Transitions**: Update GSAP animations in `parking-system.js`

## 🐛 Troubleshooting

### 3D Not Loading
- Check browser WebGL support
- Verify Three.js CDN is accessible
- Check console for JavaScript errors

### C++ Backend Issues
- Ensure C++ compiler is installed
- Check file permissions for executable
- Verify all dependencies are linked

### API Connection Problems
- Check if Node.js server is running
- Verify port 3000 is available
- Check firewall settings

## 📊 Performance

### Optimization Tips
- Use `requestAnimationFrame` for smooth animations
- Implement object pooling for vehicles
- Optimize 3D models and textures
- Use efficient data structures in C++

### Browser Compatibility
- Chrome 60+ (recommended)
- Firefox 55+
- Safari 12+
- Edge 79+

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Three.js** for amazing 3D graphics capabilities
- **GSAP** for smooth and powerful animations
- **Express.js** for robust API framework
- **Font Awesome** for beautiful icons

## 📞 Support

For support and questions:
- Create an issue on GitHub
- Contact: support@parkingmanagement.com
- Documentation: [Wiki](https://github.com/your-username/advanced-parking-management/wiki)

---

**Made with ❤️ for the future of parking management**

