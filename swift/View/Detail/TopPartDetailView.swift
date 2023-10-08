//
//  Created by Robert Petras
//  SwiftUI Masterclass ♥ Better Apps. Less Code.
//  https://swiftuimasterclass.com 
//

import SwiftUI

struct TopPartDetailView: View {
  // MARK: - PROPERTY
  
  @EnvironmentObject var shop: Shop
  @State private var isAnimating: Bool = false
  
  // MARK: - BODY
  
  var body: some View {
    HStack(alignment: .center, spacing: 6, content: {
      // PRICE
      VStack(alignment: .leading, spacing: 6, content: {
        Text("Price")
          .fontWeight(.semibold)
           
        Text(shop.selectedProduct?.formattedPrice ?? sampleProduct.formattedPrice)
          .font(.largeTitle)
          .fontWeight(.black)
          .scaleEffect(1.05, anchor: .leading)
      })
      .offset(y: isAnimating ? -50 : -75)
      
      Spacer()
      
      // PHOTO
      Image(shop.selectedProduct?.image ?? sampleProduct.image)
        .resizable()
        .scaledToFit()
        .offset(y: isAnimating ? 0 : -35)
        .frame(width: 180, height: 200, alignment: .center)
    }) //: HSTACK
    .onAppear(perform: {
      withAnimation(.easeOut(duration: 0.75)) {
        isAnimating.toggle()
      }
    })
  }
}

// MARK: - BODY

struct TopPartDetailView_Previews: PreviewProvider {
  static var previews: some View {
    TopPartDetailView()
      .environmentObject(Shop())
      .previewLayout(.sizeThatFits)
      .padding()
  }
}
