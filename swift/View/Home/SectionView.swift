//
//  Created by Robert Petras
//  SwiftUI Masterclass ♥ Better Apps. Less Code.
//  https://swiftuimasterclass.com 
//

import SwiftUI

struct SectionView: View {
  // MARK: - PROPERTY
  
  @State var rotateClockwise: Bool
  
  // MARK: - BODY
  
  var body: some View {
    VStack(spacing: 0) {
      Spacer()
      
      Text("Categories".uppercased())
        .font(.footnote)
        .fontWeight(.bold)
        .foregroundColor(.white)
        .rotationEffect(Angle(degrees: rotateClockwise ? 90 : -90))
      
      Spacer()
    } //: VSTACK
    .background(colorGray.cornerRadius(12))
    .frame(width: 85)
  }
}

// MARK: - PREVIEW

struct SectionView_Previews: PreviewProvider {
  static var previews: some View {
    SectionView(rotateClockwise: true)
      .previewLayout(.fixed(width: 120, height: 240))
      .padding()
      .background(colorBackground)
  }
}
